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
	int b = 0;
}