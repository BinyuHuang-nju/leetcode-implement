#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char> str1, str2;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == '#') {
                if (!str1.empty())
                    str1.pop_back();
            }
            else
                str1.push_back(S[i]);
        }
        for (int i = 0; i < T.length(); i++) {
            if (T[i] == '#') {
                if (!str2.empty())
                    str2.pop_back();
            }
            else
                str2.push_back(T[i]);
        }
        if (str1.size() != str2.size())
            return false;
        for (int i = 0; i < str1.size(); i++)
            if (str1[i] != str2[i])
                return false;
        return true;
    }
};