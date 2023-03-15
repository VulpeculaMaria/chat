#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Message.h"

class User
{
public:
	User(std::string name, std::string login, std::string password);
	~User();
	std::string getName();
	std::string getLogin();
	std::string getPassword();
	void addMessageToConversation(std::string conversation, Message* message);
	void printConversation(std::string conversationName) ;
private:
	std::string _name;
	std::string _login;
	std::string _password;
	std::map<std::string, std::vector<Message*>> _conversations;
};

