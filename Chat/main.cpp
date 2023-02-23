
#include <iostream>

#include "Chat.h"

using namespace std;


int main()
{
    Chat* chat = new Chat();
    int menuState = 0;
    string chatWithUserName = "";
    while (menuState != -1)
    {
        string login = "";
        string password = "";
        string msg = "";
        
        system("CLS");
        switch (menuState)
        {
        case 0:
            if (chat->isCurrentUserLogedIn())
            {
                menuState = 4;
                break;
            }
            cout << "Menu:\n";
            cout << "1. Login\n";
            cout << "2. Registration\n";
            cout << "3. Exit\n";
            cout << "input > "; cin >> menuState;
            break;

        case 1:
            
            cout << "Login:\n";
            cout << "input Login > "; cin >> login;
            if (chat->isUserExist(login) == -1)
            {
                cout << "User " << login << " dosn't exist enter password to registration:\n";
                cout << "input Password > "; cin >> password;
                chat->createUser(new User(login, password));
                // авто вход
                chat->login(login, password);
            }
            else
            {
                cout << "Hello, " << login << "\n";
                while (!chat->login(login, password))
                {
                    cout << "input Password > "; cin >> password;
                }
            }
            
            menuState = 4;
            break;

        case 2:
            cout << "Registration:\n";
            cout << "input Login > "; cin >> login;
            if (chat->isUserExist(login) == -1) // если пользователя нету то регистрация
            {
                cout << "input Password > "; cin >> password;
                chat->createUser(new User(login, password));
                // авто вход
                chat->login(login, password);
            }
            else // если пользователь уже существует то просим войти
            {
                cout << "Hello, " << login << "\n";
                while (!chat->login(login, password))
                {
                    cout << "input Password > "; cin >> password;
                }
            }
            menuState = 4;
            break;

        case 3:
            menuState = -1;
            break;

        case 4:
            cout << "Chat:\n";
            cout << "1. Show users\n";
            cout << "2. Log out\n";
            cout << "input > "; cin >> menuState;
            switch (menuState)
            {
            case 1: 
                menuState = 5;
                break;
            case 2:
                chat->logOff();
                menuState = 0;
                break;
             default:
                menuState = 4;
                break;
            }
            break;

        case 5:
            cout << "Your name: " << chat->getCurrentUser()->getLogin() << "\nUsers: " << chat->getUsersCount() << endl;
            cout << "ID  User  PWD \n";
            chat->printUsers();
            cout << "-1. Back\n";
            cout << "input > "; cin >> menuState;

            
            if (0 <= menuState && menuState < chat->getUsersCount())
            {
                chatWithUserName = chat->getUserNameByID(menuState);

                menuState = 6;
            }
            else
            {
                if (menuState == -1) 
                {
                    menuState = 4; 
                }
                else
                {
                   cout << "User not found\n"; cin >> menuState;
                   menuState = 5;
                }
            }

            break;
        case 6:
            
            cout << "Chat with " << chatWithUserName <<":\n";
            chat->getCurrentUser()->printConversation(chatWithUserName);
            cout << "input message > "; cin >> msg;
            // send message to  chatWithUserName
            
            chat->sendMessage(chat->getUserByName(chatWithUserName), new Message(chat->getCurrentUserName(), chatWithUserName, msg));
            chatWithUserName = "";
            menuState = 5;
            break;

        default:
            menuState = 0;
            break;
        }
    }
    
}
