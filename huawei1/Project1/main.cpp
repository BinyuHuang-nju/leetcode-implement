#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	string str;
	getline(cin, str);
	char* p = (char*)str.c_str();
	int len = 0, i = strlen(p);
	while (i>0 && p[i - 1] != ' ')
	{
		i--;
		len++;
	}
	cout << len << endl;
	return 0;
}