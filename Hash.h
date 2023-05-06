#pragma once
#if !defined(HASH)
#define HASH

#include <iostream>
#include <vector>
#include <string>

using namespace std;

namespace hash {
	class Hash {
		string hash;
		int receivingExitCode(int x);
		int getControlSum(string str);
	public:
		string getHash(string userString, unsigned int lenghtHash);
	};
	int Hash::receivingExitCode(int x) {
		x += 256;
		while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97))))
		{
			if (x < 48)
			{
				x += 24;
			}
			else
			{
				x -= 47;
			}
			return x;
		}
	}
	int Hash::getControlSum(string str) {

		unsigned int sault = 0;
		unsigned int strlen = 0;
		for (; strlen < str.size(); strlen++) {
			sault += int(str[strlen]);
		}
		return sault;
	}
	string Hash::getHash(string userString, unsigned int lenghtHash) {
		if (lenghtHash > 3)
		{
			unsigned int minLen = 2;
			unsigned int realMinLen = 0;
			unsigned int originalSault = this->getControlSum(userString);
			unsigned int originalLenghtStr = (userString.size());

			while (minLen <= lenghtHash)
				realMinLen = (minLen *= 2);

			while (minLen < originalLenghtStr)
				minLen *= 2;

			if ((minLen - originalLenghtStr) < minLen)
				minLen *= 2;
			
			int addCount = minLen - originalLenghtStr;

			for (int i = 0; i < addCount; i++)
				userString += this->receivingExitCode(userString[i] + userString[i + 1]);

			int maxSault = this->getControlSum(userString);
			int maxLengthStr = userString.size();

			while (userString.size() != realMinLen)
			{
				for (size_t i = 0, center = userString.size() / 2; i < center; i++)
					this->hash += this->receivingExitCode(userString[center - i] + userString[center + i]);

				userString = this->hash;
				this->hash.clear();

			}
			unsigned int rem = realMinLen - lenghtHash;
			
			for (size_t i = 0, countCompress = realMinLen/rem; this->hash.size() < (lenghtHash -4); i++)
			{
				if (i % countCompress == 0)
					this->hash += this->receivingExitCode(userString[i] + userString[++i]);
				else
					this->hash += userString[i];
			}
			this->hash += this->receivingExitCode(originalSault);
			this->hash += this->receivingExitCode(originalLenghtStr);

			this->hash += this->receivingExitCode(maxSault);
			this->hash += this->receivingExitCode(maxLengthStr);

			return this->hash;
		}
		return "";
	}
}
#endif
