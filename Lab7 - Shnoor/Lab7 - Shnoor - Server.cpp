#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include<vector>
#include <time.h>
#include <string>
#pragma warning(disable: 4996)
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

std::vector<cpp_int> openKey;
int Counter = 0;
std::vector<SOCKET> Connections;
cpp_int parserStringToInt(std::string str) {
	cpp_int num;
	bool tempBl = false;
	for (size_t i = 0; i < str.size(); i++)
	{
		num *= 10 * tempBl;
		num += int(str[i] - '0');
		tempBl = true;
	}
	return num;
}
void sendMessage(cpp_int num) {

	std::string msg1 = to_string(num);

	int msg_size = msg1.size();

	send(Connections[0], (char*)&msg_size, sizeof(int), NULL);

	send(Connections[0], msg1.c_str(), msg_size, NULL);

}
void ClientHandler() {
	srand(time(NULL));
	bool openKeyArrived = true;
	bool xArrived = true;
	int msg_size;
	int i = 0;
	cpp_int e;
	cpp_int x;
	while (true) {
		recv(Connections[0], (char*)&msg_size, sizeof(int), NULL);
		char* msg = new char[msg_size + 1];
		msg[msg_size] = '\0';
		int error = recv(Connections[0], msg, msg_size, NULL);
		std::string str_msg = msg;
		if (error == SOCKET_ERROR)
		{
			return;
		}
		if (!str_msg.empty() && str_msg != "ออออ"  && openKeyArrived)
		{
			openKey.push_back(parserStringToInt(str_msg));
			std::cout << parserStringToInt(str_msg) << std::endl;
			i++;
			if (i == 4)
				openKeyArrived = false;
		}
		else if(xArrived)
		{
			x = parserStringToInt(str_msg);
			e = rand() % 32000;
			sendMessage(e);
			xArrived = false;
		}
		else 
		{
			cpp_int s = parserStringToInt(str_msg);
			cpp_int z;
			cpp_int gs = 11444;
			for (size_t i = 0; i < s-1; i++)
				gs *= openKey[2];

			cpp_int ye = openKey[3];
			for (size_t i = 0; i < e-1; i++)
			{
				ye *= openKey[3];
			}
			z = (gs * ye) % openKey[0];
			if (x == z)
			{
				std::cout << "SUCCSESS " << x << " = " << z  << std::endl;
				
			}
			else
			{
				std::cout << "ERROR " << x << " != " << z << std::endl;
			}
			xArrived = true;
		}

		delete[] msg;
	}
}
void main() {
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 2);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(0);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);
	std::cout << "Server started.." << std::endl;
	SOCKET newConnection;
	for (size_t i = 0; i < 100; i++)
	{

		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		if (newConnection == 0) {
			std::cerr << "Error: Client connection failed.\n";
		}
		else {
			std::cout << "Client Connected!\n";
			Connections.push_back(newConnection);
			Counter++;
			//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);
		}
		for (size_t i = 0; i < openKey.size(); i++)
		{
			std::cout << openKey[i] << std::endl;
		}
	}
}