#pragma once
#include <string>

class Message
{
public:
	Message(std::string sender, std::string receiver, std::string text);
	~Message();
	std::string getMessage() const;
	std::string getSender() const;
	std::string getReceiver() const;
private:
	std::string _text;
	std::string _sender;
	std::string _receiver;
	// time
	// date
};

