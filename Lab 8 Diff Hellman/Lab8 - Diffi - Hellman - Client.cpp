//#include <iostream>
//#include <vector>
//#include <string>
//#include <iostream>
//#pragma comment(lib, "ws2_32.lib")
//#include <WinSock2.h>
//#include <vector>
//#include <time.h>
//#pragma warning(disable: 4996)
//#include <boost/multiprecision/cpp_int.hpp>
//#include <boost/random.hpp>
//#include "boost/generator_iterator.hpp"
//using boost::multiprecision::cpp_int;
//SOCKET Connection;
//// ################################## PARSER STRING TO CPP_INT ##############################
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
//// ################################## RECVIRE MESSAGE #######################################
//cpp_int ClientHandler() {
//here:
//	int msg_size;
//
//	recv(Connection, (char*)&msg_size, sizeof(int), NULL);
//
//	char* msg = new char[msg_size + 1];
//
//	msg[msg_size] = '\0';
//
//	recv(Connection, msg, msg_size, NULL);
//
//	std::string temp = msg;
//
//	delete[] msg;
//	if (temp.empty())
//		goto here;
//
//	return parserStringToInt(temp);
//
//}
//// ################################## SEND MESSAGE ############################################
//void sendMessage(cpp_int num) {
//
//	std::string msg1 = to_string(num);
//
//	int msg_size = msg1.size();
//
//	send(Connection, (char*)&msg_size, sizeof(int), NULL);
//
//	send(Connection, msg1.c_str(), msg_size, NULL);
//
//}
//// ################################## GENERATE SIMPLE NUM MOD ################################## 
//int powmod(int a, int b, int p) {
//	int res = 1;
//	while (b)
//		if (b & 1)
//			res = int(res * 1ll * a % p), --b;
//		else
//			a = int(a * 1ll * a % p), b >>= 1;
//	return res;
//}
//int generator(int p) {
//	std::vector<int> fact;
//	int phi = p - 1, n = phi;
//	for (int i = 2; i * i <= n; ++i)
//		if (n % i == 0) {
//			fact.push_back(i);
//			while (n % i == 0)
//				n /= i;
//		}
//	if (n > 1)
//		fact.push_back(n);
//
//	for (int res = 2; res <= p; ++res) {
//		bool ok = true;
//		for (size_t i = 0; i < fact.size() && ok; ++i)
//			ok &= powmod(res, phi / fact[i], p) != 1;
//		if (ok)  return res;
//	}
//	return -1;
//}
//// ################################## RAND SIMPLE NUMBER ########################################
//inline bool IsSimple(unsigned long n)
//{
//	if (n < 2)
//		return false;
//	for (unsigned long j = 2; j * j <= n; ++j)
//		if (n % j == 0)
//			return false;
//	return true;
//}
//int randSimpleInt() {
//	srand(time(NULL));
//	int a;
//	unsigned int b = -1;
//	for (unsigned long i = 1; i <= 100000; i++)
//	{
//		a = 2 + rand() % b;
//		if (IsSimple(a))
//			return a;
//	}
//}
//// ################################## RAND CPP_INT NUMBER ########################################
//cpp_int randCppIntNum() {
//	boost::random::mt19937 rng;
//	boost::random::uniform_int_distribution<> six(1, LONG_MAX);
//	return six(rng);
//}
//cpp_int exp(int g, cpp_int a) {
//	cpp_int BigNum = g;
//	for (size_t i = 0; i < a-1; i++)
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
//// ################################## MAIN #####################################################
//void main() {
//	srand(time(NULL));
//
//	WSADATA wsaData;
//	WORD DLLVersion = MAKEWORD(2, 2);
//	if (WSAStartup(DLLVersion, &wsaData) != 0)
//		return;
//
//	SOCKADDR_IN addr;
//	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
//	addr.sin_port = htons(1111);
//	addr.sin_family = AF_INET;
//
//	Connection = socket(AF_INET, SOCK_STREAM, NULL);
//
//	if (connect(Connection, (sockaddr*)&addr, sizeof(addr)) != 0)
//		return;
//	else
//		std::cout << "Connected" << std::endl;
//
//	cpp_int a("581"); //= randCppIntNum();
//	int p = randSimpleInt();
//	int g = generator(p);
//	
//	cpp_int bigA = exp(g, a) % p;
//
//	sendMessage(g);
//	sendMessage(p);
//	sendMessage(bigA);
//
//	cpp_int bigB = ClientHandler();
//	
//	cpp_int bigK = exp(bigB, a) % p;
//	std::cout << "K == " << bigK << std::endl;
//}