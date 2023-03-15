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

	void createUser(User* user);
	void deleteUser(const int index);
	void sendMessage(User* receiver, Message* message);
	void sendMessageToAll(Message* message);
	void printUsers();
	bool login(std::string login, std::string password);
	void logOff();
	bool isCurrentUserLogedIn() const;
	int isUserExist(std::string login) const;
	int getUsersCount() const;
	int getMessagesCount() const;
	std::string getCurrentUserLogin() const;
	std::string getUserLoginByID(int userID) const;
	User* getUserByID(int userID) const;
	User* getUserByLogin(std::string login) const;
	User* getCurrentUser() const;
	
private:
	User* _currentUser = nullptr;
	bool _isCurrentUserLogedIn = false;

	std::vector<Message*> _messages;
	std::vector<User*> _users;
	//std::vector<> _correspondence;
};

