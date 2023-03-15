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

void Chat::createUser( User* user)
{
	_users.emplace_back(user);
}

void Chat::deleteUser(const int& index)
{
	_users.erase(_users.begin() + index);
}

size_t Chat::isUserExist(const std::string& login) const
{
	size_t length = _users.size();
	for (size_t i = 0; i < length; i++)
	{
		if ( login == _users[i]->getLogin() ) return i;
	}
	return -1;
}

void Chat::sendMessage( User* receiver,  Message* message)
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

void Chat::sendMessageToAll( Message* message)
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
		std::cout <<  i << " " << _users[i]->getLogin() << "\t"
							<< _users[i]->getName() << "\t"
							<< _users[i]->getPassword() << std::endl;
	}
}

bool Chat::login(const std::string& login, const std::string& password)
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


size_t Chat::getUsersCount() const
{
	return _users.size();
}

size_t Chat::getMessagesCount() const
{
	return _messages.size();
}

std::string Chat::getCurrentUserLogin() const
{
	return _currentUser->getLogin();
}

std::string Chat::getUserLoginByID(const int& userID) const
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

User* Chat::getUserByID(const int& userID) const
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

User* Chat::getUserByLogin(const std::string& userName) const
{
	size_t length = _users.size();
	for (size_t i = 0; i < length; i++)
	{
		if (userName == _users[i]->getLogin()) return _users[i];
	}
	return nullptr;
}

User* Chat::getCurrentUser() const
{
	return _currentUser;
}
