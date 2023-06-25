#pragma once
#include "consts.h"

#define WIN32_LEAN_AND_MEAN
#include <iostream>
#include <windows.h>
#include <winsock2.h>
#include <WS2tcpip.h>
#include <stdio.h>
#include <string>
#include <vector>
#pragma comment (lib, "Ws2_32.lib")

class NetworkServer
{
public:
	NetworkServer();
	~NetworkServer();
	int Listen();
	int Read() ;
	int Write(const std::string& message);
	int Shutdown();
	std::string MessageConstructor(std::string text);
	int History();
	int HistoryLast();
	std::string _name;
private:
	std::vector<std::string> _history;
	WSADATA _WSADATA;

	int _iResult = 0;
	SOCKET listenSock_ = 0, clientSock_ = 0;
	sockaddr_in listenAddr_{}, clientAddr_{};
	char _R_BUF[BUF]{};
	

};

