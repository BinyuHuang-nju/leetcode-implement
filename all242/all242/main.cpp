#include <iostream>
using namespace std;
#include <map>
#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        map<char, int> smap, tmap;
        for (int i = 0; i < s.length(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        map<char, int>::iterator it1, it2;
        for (it1 = smap.begin(), it2 = tmap.begin(); it1 != smap.end(), it2 != tmap.end(); it1++, it2++) {
            if (it1->first != it2->first)
                return false;
            if (it1->second != it2->second)
                return false;
        }
        return true;
    }
};