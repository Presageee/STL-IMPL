#include "string.h"
#include <iostream>
using namespace std;
using namespace lib;

int main(int args, char* argv)
{
	lib::string str;
	lib::string str1("abcde");
	lib::string str2("12345678901234567");
	lib::string str3(str1);
	lib::string str4 = str3 + str1;
	lib::string str5 = str4 + str2;
	lib::string str6(str2);
	str6.append(str3);
	int b = 0;
	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;
	cout << str4 << endl;
	cout << str5 << endl;
	cout << str6 << endl;
}