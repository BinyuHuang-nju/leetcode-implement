#include <iostream>
using namespace std;

int main() {
	int grade[29][2] = { {5,97},
	{3,87},{2,88},{5,91},{3,91},{2,81},{4,78},{3,86},{4,86},{2,83},{2,85},{5,91},{4,85},{1,84},
	{4,60},{4,79},{2,79},{3,86},{3,88},{3,87},{3,91},{3,80},{5,71},{2,73},{2,80},{2,81},{2,85},
	{2,85},{2,84} };
	int sum1 = 0;
	for (int i = 0; i < 29; i++)
		sum1 += grade[i][0];
	double avg = 0;
	for (int i = 0; i < 29; i++) {
		avg = avg + grade[i][1] * (double)grade[i][0] / sum1;
	}
	cout << avg/20;
	return 0;
}

int func(int a, int b, int c, int d) {
	int x = 0;
	if (a) {
		// L1
	}
	else if (b) {
		// L2
		x = 1;
	}
	int y = c || d;
	if (x) {
		// L3
		if (y) {
			// L4
		}
	}
}