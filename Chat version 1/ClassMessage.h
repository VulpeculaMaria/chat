#include<iostream>
#include<string>
#include"ClassUser.h"

using namespace std;

class Message
{
    string _message;
    User *From;
    User *To;
    bool IsReaded;
    
    public:
    Message(string message): _message(message){};
    Message(){};
    ~Message(){};
};
