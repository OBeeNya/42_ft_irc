#include "../../inc/utils.hpp"

void oper(Server* server, Client* client) {
    if (!server)
        return ;
    if (client->getMessage()->getParams().size() < 2)
       client->sendMsg(ERR_NEEDMOREPARAMS + client->getNick() + " :Not enough parameters", client);
    else if (client->getMessage()->getParams()[1] != OPER_PASSWORD)
      client->sendMsg(ERR_PASSWDMISMATCH + client->getNick() +  " :Password incorrect", client);
    else if (client->getMessage()->getParams()[0] != OPER_USER)
      client->sendMsg(ERR_ERRONEUSNICKNAME + client->getNick() + " :Erroneus nickname", client);
    else {
      client->addMode('o');
      client->sendMsg(RPL_YOUREOPER + client->getNick() + " :You are now an IRC operator", client);
    }
}
