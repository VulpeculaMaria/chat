#include<iostream>
#include<string>
#include"ClassMessage.h"
#include<stdlib.h> 
using namespace std;

class Chat     //чат может использоваться как на 2 пользователя, так и на бОльшее колво пользователей
{
    User *Users; size_t UsersCount;                             //массив пользователей
    Message *Messages; size_t MessagesCount;                    //массив сообщений в конкретном чате
    
    public:
    ~Chat(){};
    Chat(){};
    Chat(User *users, size_t usercount)
    {
        Users = users;
        UsersCount = usercount;
        MessagesCount = 0;
        Users = new User[UsersCount];
        Messages = new Message[MessagesCount];

        for(int i = 0; i < usercount; ++i)
        {
            Users[i] = users[i];
        }
    }
    
    void AddMessage(Message _text);

};

void Chat::AddMessage(Message _text)
{
    MessagesCount++;
    Messages = (Message*)realloc(Messages, sizeof(Message)*MessagesCount);

    Messages[MessagesCount - 1] = _text;
}

