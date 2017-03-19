#include "stack.h"
#include <iostream>
#include <string>

#define output(k,v) std::cout << k << " is " << v << std::endl;

typedef struct data
{
	int i;
	char c;
	data():i(1), c('1') {};
	~data() {};
	friend std::ostream &operator <<(std::ostream &o, const data &d)
	{
		if (&d)
		{
			o << "int " << d.i << " char " << d.c << std::endl;
		}
		else {
			o << "is null" << std::endl;
		}	
		return o;
	}
};

int main(int argv, char* args)
{
	lib::stack<data> s;
	data d;
	std::string str(s.empty() ? "empty" : "not empty");
	output("stack", str);
	s.push(d);
	output("top", (*s.top()));
	std::string str2(s.empty() ? "empty" : "not empty");
	output("stack", str2);
	output("pop", s.pop());
	std::string str4(s.empty() ? "empty" : "not empty");
	output("stack", str4);
	lib::stack<data> s2(5);
	data c;
	c.c = '5';
	s2.push(c);
	output("top", (*s2.top()));
	output("top", (*s.top()));
	int t = 5;
	
}