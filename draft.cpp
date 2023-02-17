
#include<string>

class User
{
  string _username;
  int    _password;

  User(string username, int password);

  //пока что указала тип void, потому что это только набросок
  void ChangePassword();
  void Authorization(); // функции авторизации и регистрации, думаю, нужный функционал, но пока не совсем понимаю,
  void registration();  // как лучше их сделать, поэтому пусть будут пока что в качестве заявленнго функционала 

};

class Message
  {
    string* _SentMessage; //массивы входящих и исходящих сообщений
    string* _Incoming; 

    Message();  //конструктор который будет созздавать сообщения, затем будет вызвватт функцию отправить сообщение 
    void SendMessage(); //запишет сообщение в массив _SendMessage
    void GetMessage();  
    void ReadMessage();
  };