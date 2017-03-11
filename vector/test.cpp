#include <iostream>
#include "vector.h"
#include <stdio.h>
using namespace std;
using namespace lib;

#define output(v) for (int i = 0; i < v.size(); i++){	printf("%d item, value = %d\n", i, v[i]);};

int main(int argv, char *param)
{
	vector<int> v;
	v.add(1);
	v.add(2);
	v.add(3);
	cout << v.size() << endl;
	output(v);
	v.remove(1);
	cout << "after remove index" << endl;
	output(v);
	v.add(5);
	cout << "after remove item" << endl;
	v.removeItem(1);
	output(v);
	v.add(7);
	int a = v.find(7);
	printf("find item index %d\n", a);
	int d = v.insert(8, 2);
	printf("insert to index of 2, value = %d\n", d);
	output(v);
	printf("copy new vector\n");
	vector<int> v2(&v, 5, 10);
	output(v2);
	return 0;
}