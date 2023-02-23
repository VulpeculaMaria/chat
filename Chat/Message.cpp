#include "Message.h"
#include "User.h"

Message::Message(std::string sender, std::string receiver, std::string text) :
	_sender{ sender }, _receiver{ receiver }, _text{ text }
{
}

Message::~Message()
{
}

std::string Message::getMessage() const
{
	return _text;
}

std::string Message::getSender() const
{
	return _sender;
}

std::string Message::getReceiver() const
{
	return _receiver;
}

