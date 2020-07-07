#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> results;
        dfs(results, S, 0);
        return results;
    }
    void dfs(vector<string>& results, string S, int start) {
        if (start == S.length())
            results.push_back(S);
        else {
            if (S[start] >= '0' && S[start] <= '9')
                dfs(results, S, start + 1);
            else {
                if (S[start] >= 'a' && S[start] <= 'z') {
                    dfs(results, S, start + 1);
                    S[start] = S[start] - 32;
                    dfs(results, S, start + 1);
                }
                else {
                    dfs(results, S, start + 1);
                    S[start] = S[start] + 32;
                    dfs(results, S, start + 1);
                }
            }
        }
    }
};