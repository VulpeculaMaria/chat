#include "Chat.h"

Chat::Chat()
{

}

Chat::~Chat() 
{
	size_t length = _users.size();
	for (size_t i = 0; i < length; i++)
	{
		delete _users[i];
	}
	length = _messages.size();
	for (size_t i = 0; i < length; i++)
	{
		delete _messages[i];
	}
}

void Chat::createUser(User* user)
{
	_users.emplace_back(user);
}

void Chat::deleteUser(const int index)
{
	_users.erase(_users.begin() + index);
}

int Chat::isUserExist(std::string login) const
{
	size_t length = _users.size();
	for (size_t i = 0; i < length; i++)
	{
		if ( login == _users[i]->getLogin() ) return (int)i;
	}
	return -1;
}

void Chat::sendMessage(User* receiver, Message* message)
{
	_messages.emplace_back(message);
	if (receiver == _currentUser)
	{
		_currentUser->addMessageToConversation(receiver->getLogin(), message);
	}
	else
	{
		receiver->addMessageToConversation(_currentUser->getLogin(), message);
		_currentUser->addMessageToConversation(receiver->getLogin(), message);
	}
	
}

void Chat::sendMessageToAll(Message* message)
{
	_messages.emplace_back(message);
	size_t length = _users.size();
	for (size_t i = 0; i < length; i++)
	{
		_users[i]->addMessageToConversation("ALL", message);
	}
}

void Chat::printUsers()
{
	size_t length = _users.size();
	for (size_t i = 0; i < length; i++)
	{
		std::cout << i << " " << _users[i]->getLogin() << "\t" << _users[i]->getName() << "\t" << _users[i]->getPassword() << std::endl;
	}
}

bool Chat::login(std::string login, std::string password)
{
	
	int userID = isUserExist(login);
	if (userID == -1) return false;
	if (_users[userID]->getPassword() == password)
	{
		_currentUser = _users[userID];
		_isCurrentUserLogedIn = true;
		return true;
	}
	else
	{
		return false;
	}
}

void Chat::logOff()
{
	_currentUser = nullptr;
	_isCurrentUserLogedIn = false;
}

bool Chat::isCurrentUserLogedIn() const
{
	return _isCurrentUserLogedIn;
}


int Chat::getUsersCount() const
{
	return _users.size();
}

int Chat::getMessagesCount() const
{
	return _messages.size();
}

std::string Chat::getCurrentUserLogin() const
{
	return _currentUser->getLogin();
}

std::string Chat::getUserLoginByID(int userID) const
{
	try
	{
		return _users[userID]->getLogin();
	}
	catch (const std::exception&)
	{
		return "!user";
	}
	
}

User* Chat::getUserByID(int userID) const
{
	try
	{
		return _users[userID];
	}
	catch (const std::exception&)
	{
		return nullptr;
	}
}

User* Chat::getUserByLogin(std::string userName) const
{
	int length = _users.size();
	for (int i = 0; i < length; i++)
	{
		if (userName == _users[i]->getLogin()) return _users[i];
	}
	return nullptr;
}

User* Chat::getCurrentUser() const
{
	return _currentUser;
}
