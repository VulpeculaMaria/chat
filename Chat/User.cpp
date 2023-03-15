#include "User.h"


User::User(const std::string& name, const std::string& login, const std::string& password) :
	_name{ name }, _login{ login }, _password{ password }
{
}

User::~User()
{
}

std::string User::getName() const
{
	return _name;
}

std::string User::getLogin() const
{
	return _login;
}

std::string User::getPassword() const
{
	return _password;
}

void User::addMessageToConversation(const std::string& conversation, Message* message)
{
	_conversations[conversation].emplace_back(message);
}

void User::printConversation(const std::string& conversationName)
{
	size_t convSize = _conversations[conversationName].size();
	for (size_t i = 0; i < convSize; i++)
	{
		std::cout << _conversations[conversationName][i]->getSender() << ": " << _conversations[conversationName][i]->getMessage() << "\n";
	}
}

