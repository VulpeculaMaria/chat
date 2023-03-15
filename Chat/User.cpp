#include "User.h"


User::User(std::string name, std::string login, std::string password) :
	_name{ name }, _login{ login }, _password{ password }
{
}

User::~User()
{
}

std::string User::getName()
{
	return _name;
}

std::string User::getLogin()
{
	return _login;
}

std::string User::getPassword()
{
	return _password;
}

void User::addMessageToConversation(std::string conversation, Message* message)
{
	_conversations[conversation].emplace_back(message);
}

void User::printConversation(std::string conversationName) 
{
	size_t convSize = _conversations[conversationName].size();
	for (size_t i = 0; i < convSize; i++)
	{
		std::cout << _conversations[conversationName][i]->getSender() << ": " << _conversations[conversationName][i]->getMessage() << "\n";
	}
}

