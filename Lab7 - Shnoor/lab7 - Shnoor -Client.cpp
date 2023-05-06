#include <iostream>
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <string>
#include <vector>
#include <time.h>
#pragma warning(disable: 4996)

#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;
SOCKET Connection;
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
cpp_int ClientHandler() {
	here:
	int msg_size;

	recv(Connection, (char*)&msg_size, sizeof(int), NULL);

	char* msg = new char[msg_size + 1];

	msg[msg_size] = '\0';

	recv(Connection, msg, msg_size, NULL);

	std::string temp = msg;

	delete[] msg;
	if (temp.empty())
		goto here;
	
	return parserStringToInt(temp);

}
void sendMessage(cpp_int num) {

	std::string msg1 = to_string(num);

	int msg_size = msg1.size();

	send(Connection, (char*)&msg_size, sizeof(int), NULL);

	send(Connection, msg1.c_str(), msg_size, NULL);

}
void main()
{
	srand(time(NULL));

	WSADATA wsaData;
	WORD DLLVersion = MAKEWORD(2, 2);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
		return;

	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);

	if (connect(Connection, (sockaddr*)&addr, sizeof(addr)) != 0)
		return;
	else
		std::cout << "Connected" << std::endl;

	//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

	std::vector<std::pair<std::string, cpp_int>> openKey = { {"p",48731}, {"q", 443}, {"g", 11444}, {"y", 0} };
	int  w = 357;

	cpp_int y("11444");
	for (size_t i = 0; i < openKey[1].second - w - 1; i++)
	{
		y *= 11444;
	}
	y %= 48731;
	openKey[3].second = y;

	for (size_t i = 0; i < openKey.size(); i++)
	{
		sendMessage(openKey[i].second);
	}

	for (size_t i = 0; i < 3; i++)
	{
		cpp_int r = rand() % (openKey[1].second - 1);
		cpp_int x = openKey[2].second;
		for (size_t i = 0; i < r-1; i++)
		{
			x *= openKey[2].second;
		}
		x %= openKey[0].second;
		std::cout << x << std::endl;
		sendMessage(x);
		cpp_int e = ClientHandler();
		cpp_int s = (r + w * e)%openKey[1].second;
		sendMessage(s);
	}
}