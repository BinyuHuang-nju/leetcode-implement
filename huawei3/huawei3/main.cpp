#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include <stdio.h>
#include <vector>
#include <algorithm>

int main()
{
	int num = 0, dig;
	while (scanf("%d", &num) != EOF) {
		//cin >> num;
		vector<int> store;
		/*	while (scanf("%d", &dig) != EOF)
			{
				cin >> dig;
				if (find(store.begin(), store.end(), dig) == store.end())
					store.emplace_back(dig);
			}
			*/
		for (int i = 0; i < num; i++)
		{
			cin >> dig;
			if (find(store.begin(), store.end(), dig) == store.end())
				store.emplace_back(dig);
		}
		sort(store.begin(), store.end());
		for (int i = 0; i < store.size(); i++)
			cout << store[i] << endl;
	}
	return 0;
}