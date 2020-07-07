#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <map>

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> hashmap;
		int i = 0, longest = 0;
		for (int j = 0; j < s.length(); j++) {
			hashmap[s[j]]++;
			while (hashmap[s[j]] > 1) {
				hashmap[s[i]]--;
				i++;
			}
			if (longest < j - i + 1)
				longest = j - i + 1;
		}
		return longest;
	}
};
int main() {
	string str;
	getline(cin, str);
	Solution sol;
	int re = sol.lengthOfLongestSubstring(str);
	cout << re;
	return 0;
}