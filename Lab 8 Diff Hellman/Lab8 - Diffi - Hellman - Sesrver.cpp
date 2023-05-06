//#pragma comment(lib, "ws2_32.lib")
//#include <winsock2.h>
//#include <iostream>
//#include<vector>
//#include <time.h>
//#include <string>
//#pragma warning(disable: 4996)
//#include <boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int;
//std::vector<SOCKET> Connections;
//cpp_int exp(int g, cpp_int a) {
//	cpp_int BigNum = g;
//	for (size_t i = 0; i < a - 1; i++)
//	{
//		BigNum *= g;
//	}
//	return BigNum;
//}
//cpp_int exp(cpp_int g, cpp_int a) {
//	cpp_int BigNum = g;
//	for (size_t i = 0; i < a - 1; i++)
//	{
//		BigNum *= g;
//	}
//	return BigNum;
//}
//cpp_int parserStringToInt(std::string str) {
//	cpp_int num;
//	bool tempBl = false;
//	for (size_t i = 0; i < str.size(); i++)
//	{
//		num *= 10 * tempBl;
//		num += int(str[i] - '0');
//		tempBl = true;
//	}
//	return num;
//}
//void sendMessage(cpp_int num) {
//
//	std::string msg1 = to_string(num);
//
//	int msg_size = msg1.size();
//
//	send(Connections[0], (char*)&msg_size, sizeof(int), NULL);
//
//	send(Connections[0], msg1.c_str(), msg_size, NULL);
//
//}
//void ClientHandler() {
//
//	cpp_int b("581");
//	srand(time(NULL));
//	std::vector<cpp_int> nums;
//	int msg_size;
//	int i = 0;
//	while (i != 3) {
//		recv(Connections[0], (char*)&msg_size, sizeof(int), NULL);
//		char* msg = new char[msg_size + 1];
//		msg[msg_size] = '\0';
//		int error = recv(Connections[0], msg, msg_size, NULL);
//		std::string str_msg = msg;
//
//		nums.push_back(parserStringToInt(str_msg));
//		i++;
//	}
//	sendMessage((exp(nums[0], b) % nums[1]));
//	cpp_int K = exp(nums[2], b) % nums[1];
//	std::cout << "K == " << K << std::endl;
//	return;
//}
//void main() {
//	WSAData wsaData;
//	WORD DLLVersion = MAKEWORD(2, 2);
//	if (WSAStartup(DLLVersion, &wsaData) != 0) {
//		std::cout << "Error" << std::endl;
//		exit(0);
//	}
//
//	SOCKADDR_IN addr;
//	int sizeofaddr = sizeof(addr);
//	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	addr.sin_port = htons(1111);
//	addr.sin_family = AF_INET;
//
//	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
//	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
//	listen(sListen, SOMAXCONN);
//	std::cout << "Server started.." << std::endl;
//	SOCKET newConnection;
//	for (size_t i = 0; i < 100; i++)
//	{
//		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
//
//		if (newConnection == 0) {
//			std::cerr << "Error: Client connection failed.\n";
//		}
//		else {
//			std::cout << "Client Connected!\n";
//			Connections.push_back(newConnection);
//			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);
//		}
//	}
//}