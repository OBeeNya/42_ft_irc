#include "../../inc/utils.hpp"

void	nick(Server* server, Client* client) {
	if (!server)
		return ;
	if (!client->getWelcome()) {
		if (!checkCommand(client->getMessage()->getParams()[0]) || client->getMessage()->getParams()[0].size() > 9)
			client->sendMsg(ERR_ERRONEUSNICKNAME " :Erroneous nickname", client);
		else if (server->nickIsUsed(client->getMessage()->getParams()[0])) {
			client->sendMsg(ERR_NICKNAMEINUSE + client->getMessage()->getParams()[0] + " " + client->getMessage()->getParams()[0] + " :Nickname is already in use", client);
		}
		else
			client->setNick(client->getMessage()->getParams()[0]);
		return ;
	}
	if (client->getMessage()->getParams().size() == 0)
		client->sendMsg(ERR_NONICKNAMEGIVEN " :No nickname given", client);
	else if (!checkCommand(client->getMessage()->getParams()[0]) || client->getMessage()->getParams()[0].size() > 9)
		client->sendMsg(ERR_ERRONEUSNICKNAME + client->getNick() + " :Erroneous nickname", client);
	else if (server->nickIsUsed(client->getMessage()->getParams()[0]))
		client->sendMsg(ERR_NICKNAMEINUSE + client->getMessage()->getParams()[0] + " " + client->getMessage()->getParams()[0] + " :Nickname is already in use", client);
	else if (client->getAuthorized()) {
		client->sendMsg("NICK " + client->getMessage()->getParams()[0], client);
		client->setNick(client->getMessage()->getParams()[0]);
		if (client->getChannelName().size()) {
			std::map<std::string, Channel>::iterator	it = server->getChannels().begin();
			while (it != server->getChannels().end()) {
				if ((it->first) == client->getChannelName()) {
					it->second.broadcast(client, " changed nickname to " + client->getMessage()->getParams()[0]);
					break ;
				}
				it++;
			}
		}
	}
}
