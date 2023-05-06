//#include <iostream>
//#include "SHA256.h"
//#include <cstddef>
//#include <bitset>
//#include <vector>
//#include <time.h>
//#include <fstream>
//using namespace std;
//// ------------------------------- THE SAME OPERATION LIKE WITH MESSAGE --------------------------------------
////                                      SHA + REHASHING INTO BIN
//vector<bitset<1>> parsIntToString(int randNum) {
//
//	string str = to_string(randNum);
//
//	SHA256 sha;
//
//	sha.update(str);
//
//	uint8_t* digest = sha.digest();
//
//	str = SHA256::toString(digest);
//
//	vector<bitset<1>> bit;
//	for (size_t i = 0; i < str.size(); i += 8)
//	{
//		bit.push_back(bitset<1>(str[i]));
//	}
//
//	return bit;
//}
////----------------------------------- OUTPUT --------------------------------
//void fork_output(vector<bitset<1>> bt) {
//
//	for (size_t j = 0; j < bt.size(); j++)
//	{
//		cout << bt[j];
//	}
//}
//void output(vector<bitset<1>> vec, vector<pair<vector<bitset<1>>, vector<bitset<1>>>> binRand) {
//
//	cout << "############# HASHED MESSAGE ################\n" << endl;
//
//	for (auto v : vec)
//		cout << v;
//
//
//	cout << "\n\n########### HASHED RANDOM NUMBERS #########\n" << endl;
//
//	for (size_t i = 0; i < binRand.size(); i++)
//	{
//		vec = binRand[i].first;
//		cout << " [ "; fork_output(vec); cout << " , "; vec = binRand[i].second; fork_output(vec); cout << " ]" << endl;
//	}
//}
//void main()
//{
//	srand(time(NULL));
//	// ----------------------- SHA256 -------------------------
//	string str; // ------------------------------------------------------ ALICE MESSAGE
//
//	cout << "Input your message: "; cin >> str; cout << endl;
//
//	SHA256 sha;
//
//	sha.update(str);
//
//	uint8_t* digest = sha.digest();// ----------------------------------- INPUT TO SHA STRING
//
//	//cout << SHA256::toString(digest) << endl;
//	string binSHA = SHA256::toString(digest);
//
//	// _________________________________________________________________________________ БОБ ХЕШИРУЕТ СООБЩЕНИЕ ЭТИМ АЛГОРИТМОМ
//	// ---------------------- VECTOR BIN MESSAGE ---------------
//	vector<bitset<1>> binInt;
//	for (auto c : binSHA) {
//
//		if (bitset<1>(c) == '0')
//			binInt.push_back(0);
//		else
//			binInt.push_back(1);
//	}
//	// ---------------------- RANDOM NUMS -----------------------
//
//	vector<pair<int, int>> notHeshed; // ------------------------------------------- НЕ хешированные случайные числа
//
//	vector<pair<vector<bitset<1>>, vector<bitset<1>>>> binRand; // ----------------- хешированные случайны числа
//
//	// __________________________________________________________________________________       БОБ ДЕЛАЕТ ТО ЖЕ (стр10)
//	//                                                                                     САМОЕ С ПОДПИСЬЮ И ПРОВЕРЯЕТ НА
//	//                                                                                                ОТКРЫТОМ КЛЮЧЕ
//	for (size_t i = 0; i < (binSHA.size()); i++)
//	{
//		pair<vector<bitset<1>>, vector<bitset<1>>> pr;
//		pair<int, int> nonH;
//		for (size_t j = 0; j < 2; j++)
//		{
//			int randInt = rand() % 255;
//
//			if (j == 0) {
//				pr.first = parsIntToString(randInt);
//				nonH.first = randInt;
//			}
//			else {
//				pr.second = parsIntToString(randInt);
//				nonH.second = randInt;
//			}
//		}
//		notHeshed.push_back(nonH);
//		binRand.push_back(pr);
//	}
//
//	output(binInt, binRand);
//
//	cout << "\n\n############# SIGNATURE ############\n\n";
//
//	ofstream lamp("All.txt");
//
//	lamp << "Message: " << str << endl;
//
//	lamp << "Signature: ";
//
//	for (size_t i = 0; i < binInt.size(); i++)
//	{
//		if (binInt[i] == 0)
//		{
//			cout << notHeshed[i].first << " ";
//			lamp << notHeshed[i].first << ";";
//		}
//		else
//		{
//			cout << notHeshed[i].second << " ";
//			lamp << notHeshed[i].second << ";";
//		}
//	}
//	lamp.close();
//
//	ofstream openKey("OpenKey.txt");
//	for (size_t i = 0; i < binRand.size(); i++)
//	{
//		for (size_t j = 0;  j < binRand[i].first.size();  j++)
//		{
//			openKey << binRand[i].first[j];
//			
//		}
//		openKey << ";";
//		for (size_t k = 0; k < binRand[i].second.size(); k++)
//		{
//			openKey << binRand[i].second[k];
//		}
//		openKey << endl;
//	}
//	openKey.close();
//}