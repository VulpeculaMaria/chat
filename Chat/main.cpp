
#include <iostream>

#include "Chat.h"

#define MENU_FIRST_SCREEN                   0
#define MENU_LOGIN_SCREEN                   1
#define MENU_REGISTRATION_SCREEN            2
#define MENU_EXIT_PROGRAM                   3
#define MENU_CHAT_SCREEN                    4
#define MENU_SELECT_USER_SCREEN             5
#define MENU_CHAT_WITH_SCREEN               6
#define MENU_CHAT_WITH_ALL_USERS_SCREEN     7

int main()
{
    Chat* chat = new Chat();
    int menuState = 0;
    std::string chatWithUserLogin = "";
    
    // добавим несколько пользователей
    chat->createUser(new User("User", "user", "123"));
    chat->createUser(new User("Arkadyi", "defaultUser1", "123"));
    chat->createUser(new User("Petr", "defaultUser2", "123"));
    chat->createUser(new User("Arsenyi", "defaultUser3", "123"));

    while (menuState != -1)
    {
        std::string login = "";
        std::string password = "";
        std::string name = "";
        std::string msg = "";
        
        system("CLS");
        if (chat->isCurrentUserLogedIn())
        {
            std::cout << "Your Login: " << chat->getCurrentUser()->getLogin() <<
                " Your Name: " << chat->getCurrentUser()->getName() << 
                "\nUsers: " << chat->getUsersCount() << " Messages: " << chat->getMessagesCount() <<  "\n\n";
        }
        switch (menuState)
        {
        case MENU_FIRST_SCREEN:
            if (chat->isCurrentUserLogedIn())
            {
                menuState = MENU_CHAT_SCREEN;
                break;
            }
            std::cout << "Menu:\n";
            std::cout << "1. Login\n";
            std::cout << "2. Registration\n";
            std::cout << "3. Exit\n";
            std::cout << "input menu > "; std::cin >> menuState;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                menuState = MENU_FIRST_SCREEN;
            }
            break;

        case MENU_LOGIN_SCREEN:
            
            std::cout << "Login:\n";
            std::cout << "input Login > "; std::cin >> login;
            if (chat->isUserExist(login) == -1)
            {
                std::cout << "User " << login << " dosn't exist enter name and password to registration:\n";
                std::cout << "input Name > "; std::cin >> name;
                std::cout << "input Password > "; std::cin >> password;
                chat->createUser(new User(name, login, password));
                // авто вход
                chat->login(login, password);
            }
            else
            {
                std::cout << "Hello, " << login << "\n";
                while (!chat->login(login, password))
                {
                    std::cout << "input Password > "; std::cin >> password;
                }
            }
            
            menuState = MENU_CHAT_SCREEN;
            break;

        case MENU_REGISTRATION_SCREEN:
            std::cout << "Registration:\n";
            std::cout << "input Login > "; std::cin >> login;
            if (chat->isUserExist(login) == -1) // если пользователя нету то регистрация
            {
                std::cout << "input Name > "; std::cin >> name;
                std::cout << "input Password > "; std::cin >> password;
                chat->createUser(new User(name, login, password));
                // авто вход
                chat->login(login, password);
            }
            else // если пользователь уже существует то просим войти
            {
                std::cout << "Hello, " << chat->getUserByLogin(login)->getName() << "\n";
                while (!chat->login(login, password))
                {
                    std::cout << "input Password > "; std::cin >> password;
                }
            }
            menuState = MENU_CHAT_SCREEN;
            break;

        case MENU_EXIT_PROGRAM:
            menuState = -1;
            break;

        case MENU_CHAT_SCREEN:
            std::cout << "Chat:\n";
            std::cout << "1. General chat\n";
            std::cout << "2. Show users to chating\n";
            std::cout << "3. Log out\n";
            std::cout << "input menu > "; std::cin >> menuState;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                menuState = MENU_CHAT_SCREEN;
            }
            switch (menuState)
            {
            case 1:
                menuState = 7;
                break;
            case 2: 
                menuState = 5;
                break;
            case 3:
                chat->logOff();
                menuState = 0;
                break;
             default:
                menuState = MENU_CHAT_SCREEN;
                break;
            }
            break;

        case MENU_SELECT_USER_SCREEN:
            
            std::cout << "ID  Login  Name  PWD \n";
            chat->printUsers();
            std::cout << "____________________________________________\n";
            std::cout << "type ID or -1 to Back\n";
            std::cout << "input user id > "; std::cin >> menuState;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                menuState = MENU_SELECT_USER_SCREEN;
            }
            
            if (0 <= menuState && menuState < chat->getUsersCount())
            {
                chatWithUserLogin = chat->getUserLoginByID(menuState);

                menuState = MENU_CHAT_WITH_SCREEN;
            }
            else
            {
                if (menuState == -1) 
                {
                    menuState = MENU_CHAT_SCREEN;
                }
                else
                {
                   //std::cout << "User not found\n"; std::cin >> menuState;
                   menuState = MENU_SELECT_USER_SCREEN;
                }
            }

            break;
        case MENU_CHAT_WITH_SCREEN:
            
            std::cout << "Chat with " << chatWithUserLogin <<":\n";
            chat->getCurrentUser()->printConversation(chatWithUserLogin);

            std::cout << "____________________________________________\n";
            std::cout << " 1. send message\n-1. back\n";
            std::cout << "input menu > "; std::cin >> menuState;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                menuState = MENU_CHAT_WITH_SCREEN;
            }
            switch (menuState)
            {
            case MENU_CHAT_WITH_SCREEN: break;
            case -1:
                chatWithUserLogin = "";
                menuState = MENU_SELECT_USER_SCREEN;
                break;
            case 1:
                std::cout << "input message > ";
                //cin >> msg;
                std::getline(std::cin >> std::ws, msg); // ввод сообщения с пробелами
                // send message to  chatWithUserName
                chat->sendMessage(chat->getUserByLogin(chatWithUserLogin), new Message(chat->getCurrentUserLogin(), chatWithUserLogin, msg));
                menuState = MENU_CHAT_WITH_SCREEN;
                break;
            default:
                
                menuState = MENU_SELECT_USER_SCREEN;
                break;
            }
            break;

        case MENU_CHAT_WITH_ALL_USERS_SCREEN:

            std::cout << "Chat with all users:\n";
            chat->getCurrentUser()->printConversation("ALL");

            std::cout << "____________________________________________\n";
            std::cout << " 1. send message\n-1. back\n";
            std::cout << "input menu > "; std::cin >> menuState;
            if (std::cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                menuState = MENU_CHAT_WITH_ALL_USERS_SCREEN;
            }
            switch (menuState)
            {
            case MENU_CHAT_WITH_ALL_USERS_SCREEN: break;
            case -1:
                menuState = MENU_CHAT_SCREEN;
                break;
            case 1:
                std::cout << "input message > ";
                std::getline(std::cin >> std::ws, msg); // ввод сообщения с пробелами

                chat->sendMessageToAll(new Message(chat->getCurrentUserLogin(), "ALL", msg));
                menuState = MENU_CHAT_WITH_ALL_USERS_SCREEN;
                break;
            default:
                menuState = MENU_CHAT_SCREEN;
                break;
            }
            break;

        default:
            menuState = MENU_FIRST_SCREEN;
            break;
        }
    }
    delete chat;
}
