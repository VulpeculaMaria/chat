
#include<iostream>
#include<string>

using namespace std;

class User
{
    string _NameUser;
    string _Password;

    public:
    ~User(){};
    User();
    User(string login, string password);  

};

User::User(string login, string password): _NameUser(login), _Password(password){}
User::User(){};


