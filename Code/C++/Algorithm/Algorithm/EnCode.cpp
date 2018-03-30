#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int mainEncode()
{
	char str1[100];
	gets_s(str1);
	string str = str1;
	for (int i = 0; i < str.size(); i++)
	{
		if ((str[i] > 'a' && str[i] < 'z') || (str[i] > 'A' && str[i] < 'Z'))
		{
			str[i] = str[i] + 1;
		}
		else if (str[i] == 'z')
		{
			str[i] = 'a';
		}
		else if (str[i] == 'Z')
		{
			str[i] = 'A';
		}
	}
	cout << str;
	return 1;
}