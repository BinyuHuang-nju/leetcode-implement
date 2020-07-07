#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        if (s.length() < p.length())
            return res;
        int map_p[26] = { 0 }, map_subs[26] = { 0 };
        int i, j, sl = s.length(), pl = p.length();
        for (i = 0; i < pl; i++)
        {
            map_subs[s[i] - 'a']++;
            map_p[p[i] - 'a']++;
        }
        i = 0;
        while ( i <= sl - pl) {
            for (j = 0; j < 26; j++)
                if (map_subs[j] != map_p[j])
                    break;
            if (j == 26) {
                res.push_back(i);
                while (i < sl - pl && s[i] == s[i + pl]) {
                    res.push_back(i + 1);
                    i++;
                }
            }
            if (i < sl - pl) {
                map_subs[s[i]-'a']--;
                map_subs[s[i + pl]-'a']++;
            }
            i++;
        }
        return res;
    }
};