#include "../../inc/utils.hpp"

std::ostream& operator<<(std::ostream& out, const std::vector<std::string>& vec) {
    out << "[ ";
    for (std::vector<std::string>::const_iterator it = vec.begin(); it != vec.end(); ++it)
        out << *it << " ";
    out << "]";
    return (out);
}

void    kick(Server* server, Client* client) {
    if (!server)
        return ;
    std::string msg;
    if (client->getMessage()->getParams().size() < 3) {
        client->sendMsg(ERR_NEEDMOREPARAMS + client->getNick() + " :Not enough parameters", client);}
	std::string chan = client->getMessage()->getParams()[0];
	std::vector<std::string> users = ft_split(client->getMessage()->getParams()[1], ",");
    if (server->getChannels().count(chan) == 0)
            client->sendMsg(ERR_NOSUCHCHANNEL + client->getNick() + " " + chan + " :No such channel", client);
    else if (!client->getModes().find('o')->second)
        client->sendMsg(ERR_CHANOPRIVSNEEDED + client->getNick() +  " :You're not channel operator", client);
    else {
        Channel*	channel = server->getChannelByName(chan);
        for (std::vector<std::string>::iterator it = users.begin(); it != users.end(); ++it) {
            if (server->getClientByNick(*it) == NULL || !channel->ifMemberbyNick(*it))
                    client->sendMsg(ERR_USERNOTINCHANNEL + client->getNick() + " " + chan + " " + *it  + " :They aren't on that channel", client);
            else {
                size_t i = client->getMessage()->getParams()[2].find(":");
                std::string msg = "";
                if (i != std::string::npos)
                        msg = client->getMessage()->getParams()[2].substr(i + 1);
                std::string str =  "KICK " + chan + " " + *it + " :" + msg;
                //send message to all users of the channel - broadcast
                channel->broadcast(client, str);
				//a message to the concerned user
                server->getClientByNick(*it)->sendMsg(str, server->getClientByNick(*it));
				channel->removeMember(server->getClientByNick(*it));
                server->getClientByNick(*it)->getMessage()->getParams().clear();
                server->getClientByNick(*it)->getMessage()->getParams().push_back(chan);
            }
        }
    }
}
