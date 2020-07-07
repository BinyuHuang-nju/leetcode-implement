#include <iostream>
using namespace std;
#include <string>
#include <cstring>

void outsubstr(char src[], int begin, int end) {

	for (int i = begin; i <= end; i++)
		cout << src[i];
	for (int i = 0; i < 7 + begin - end; i++)
		cout << "0";
	cout << endl;
}
int main() {
	char str[2][100];
	cin.getline(str[0],100);
	cin.getline(str[1], 100);
	int num[2] = { (int)strlen(str[0]),  (int)strlen(str[1]) };
	int interval, tail;
//	cout << num1 << " " << num2;
	for (int time = 0; time < 2; time++) {
		interval = num[time] / 8;
		tail = num[time] - interval * 8;
		for (int i = 0; i < interval; i++) {
			outsubstr(str[time], i * 8, i * 8 + 7);
		}
		if (tail > 0)
			outsubstr(str[time], interval * 8, num[time] - 1);
	}
	return 0;
}

bool symmetry(string str) {
	for (int i = 0, j = str.length() - 1; i < j; i++, j--) {
		if (str[i] != str[j])
			return false;
	}
	return true;
}
int main() {
	string str;
	getline(cin, str);
	printf("%d", symmetry(str));
	return 0;
}