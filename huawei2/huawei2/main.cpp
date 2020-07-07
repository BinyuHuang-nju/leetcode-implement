#include <iostream>
using namespace std;
#include <string>
#include <cstring>

int main()
{
	string str;
	getline(cin, str);
	char target;
	cin >> target;
	if (target >= 'a' && target <= 'z')
		target = target - 32;
	int result = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') 
			str[i] = str[i] - 32;
		if (str[i] == target)
			result++;
	}
	cout << result;
	return 0;
}