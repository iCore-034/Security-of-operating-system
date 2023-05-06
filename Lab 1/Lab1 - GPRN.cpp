//#include <iostream>
//#include <string>
//#include <Windows.h>
//#include <vector>
//#include <time.h>
//#include <bitset>
//using namespace std;
//string intput_user_seed() {
//
//    cout << " ################## Input your seed ################## " << endl;
//    string str;
//    cin >> str;
//    return str;
//}
//int generate_num(long long value, int instr, string str) {
//    srand(time(NULL));
//    // Из value в итоге останется 1 число, докрутить к нему instr и сделать цикл, который добавляет к value по 1 числу из str
//    // Если out of range будет выскакивать в цикле с str, то скидываем показатель i, перебирающий str до какого-то значения (можно случайного)
//    MEMORYSTATUS ms;
//    GlobalMemoryStatus(&ms);
//    long long rnd = ((str.length()*ms.dwAvailPhys) * 73129 + 95121) % INT_MAX;
//    instr = instr + (ms.dwAvailPhys % (instr + str[rnd%str.length()]));
//    long long endNum = ((value * instr) * rnd + (value * str.length() * ((int)str[rand() % str.length()] - '0'))) % 11;
//
//    return endNum;
//}
//int main()
//{
//    vector<int> rand_num;
//    // ------------------------------ OS Seed -----------------------------------
//    MEMORYSTATUS ms;
//    GlobalMemoryStatus(&ms);
//    long long  value = (long long)ms.dwAvailPhys;
//    // ------------------------------ User Seed ---------------------------------
//    string str = intput_user_seed();
//    int instr = 0;
//    for (size_t i = 0; i < str.length(); i++)
//    {
//        instr += str[i] - '0';
//    }
//
//    for (int i = 0; i < 128; ++i)
//    {
//        value = (value * 73129 + 95121) % 10000000000000000000;
//        if (value < 0)
//        {
//            value += value;
//            value += value;
//        }
//        rand_num.push_back(generate_num(value, instr, str));
//    }  
//    if (rand_num.size() > 128)
//    {
//        rand_num.erase(rand_num.begin(), rand_num.begin()+(rand_num.size()-128));
//    }
//    cout << " ##################### NUMBER 128 BIT ##################### " << endl;
//    for (int i : rand_num) {
//        cout << i;
//    }
//
//    vector<bitset<1>> bits;
//    for (int i: rand_num) {
//        bits.push_back(bitset<1>(i));
//    }
//    cout << endl;
//    for (auto i : bits) {
//        cout << i;
//    }
//    cout << endl;
//}