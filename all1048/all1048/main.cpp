#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

class Solution1 {
public:
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        if (len < 2)
            return len;
        vector<int> list(len, 1);
        int maxlen = 1;
        sort(words.begin(), words.end(), [](string a, string b) {return a.length() < b.length(); });
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (isPre(words[j], words[i]))
                    list[i] = max(list[i], list[j] + 1);
            }
            if (maxlen < list[i])
                maxlen = list[i];
        }
        return maxlen;
    }
    bool isPre(string str1, string str2) {
        if (str1.length() + 1 != str2.length())
            return false;
        int i = 0, j = 0, faults = 0;
        for (; i < str1.length() && j < str2.length();) {
            if (str1[i] == str2[j]) {
                i++;
                j++;
            }
            else {
                faults++;
                if (faults > 1)
                    return false;
                j++;
            }
        }
        return true;
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int len = words.size();
        if (len < 2)
            return len;
        vector<int> list(len, 1);
        int maxlen = 1;
        sort(words.begin(), words.end(), [](string a, string b) {return a.length() < b.length(); });
        map<string, int> mp;
        for (int i = 0; i < len; i++) {
            mp[words[i]] = i+1;
            if (i > 0 && words[i].length() >= 2) {
                for (int j = 0; j < words[i].length(); j++) {
                    string str = words[i].substr(0, j) + words[i].substr(j + 1, words[i].length() - j - 1);
                    if (mp[str])
                        list[i] = max(list[i], list[mp[str]-1] + 1);
                }
                if (maxlen < list[i])
                    maxlen = list[i];
            }
        }
        return maxlen;
    }
};


int main() {
    //vector<string> a = { "ksqvsyq","ks","kss","czvh","zczpzvdhx","zczpzvh","zczpzvhx","zcpzvh","zczvh","gr","grukmj","ksqvsq","gruj","kssq","ksqsq","grukkmj","grukj","zczpzfvdhx","gru" };
    vector<string> a ={"sgtnz", "sgtz", "sgz", "ikrcyoglz", "ajelpkpx", "ajelpkpxm", "srqgtnz", "srqgotnz", "srgtnz", "ijkrcyoglz"};
    Solution sol;
    int re =sol.longestStrChain(a);
    return 0;
}