#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <map>
class Solution {
public:
    bool canConstruct(string s, int k) {
        if (s.length() < k)
            return false;
        map<char, int> mp;
        for (char ch : s) {
            if (!mp.count(ch))
                mp[ch] = 1;
            else
                mp[ch]++;
        }
        int one = 0;
        for (auto m : mp) {
            if (m.second & 1)
                one++;
        }
        return one <= k;
    }
};