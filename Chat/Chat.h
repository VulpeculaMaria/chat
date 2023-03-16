#pragma once
#include <iostream>
#include "Message.h"
#include "User.h"
#include <vector>

class Chat
{

public:
	Chat();
	~Chat();

	void createUser( User* user);
	void createAdminUser(User* user);
	void deleteUser(const int& index);
	void sendMessage( User* receiver, Message* message);
	void sendMessageToAll(Message* message);
	void printUsers();
	void printMessages();
	bool login(const std::string& login, const std::string& password);
	void logOff();
	bool isCurrentUserLogedIn() const;
	bool isCurrentUserAdmin() const;
	size_t isUserExist(const std::string& login) const;
	size_t getUsersCount() const;
	size_t getMessagesCount() const;
	std::string getCurrentUserLogin() const;
	std::string getUserLoginByID(const int& userID) const;
	User* getUserByID(const int& userID) const;
	User* getUserByLogin(const std::string& login) const;
	User* getCurrentUser() const;
	
private:
	User* _currentUser = nullptr;
	bool _isCurrentUserLogedIn = false;

	std::vector<Message*> _messages;
	std::vector<User*> _users;
};

