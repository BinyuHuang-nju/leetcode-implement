#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> list;
        dfs(S, 0, list);
        return list;
    }
private:
    bool dfs(string S, int start, vector<int>& list) {
        if (start == S.length())
            return list.size() > 2;
        for (int i = start; i < S.length(); i++) {
            string temp = S.substr(start, i - start + 1);
            if ((S[start] == '0' && i > start) || i - start > 9 || stoll(temp) > (long long)INT_MAX)
                break;
            int cur = stoi(temp);
            int first = list.size() >= 2 ? list[list.size() - 2] : -1;
            int second = list.size() >= 1 ? list[list.size() - 1] : -1;
            if ((long long)first + second > (long long)INT_MAX)
                break;
            list.push_back(cur);
            if ((first == -1 || second == -1 || first + second == cur) && dfs(S, i + 1, list))
                return true;
            list.pop_back();
        }
        return false;
    }
};