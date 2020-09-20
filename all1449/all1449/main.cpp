#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <map>
class Solution1 {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<vector<string>> dp(9 + 1, vector<string>(target + 1, ""));
        for (int j = 1; j <= target; j++)
            dp[0][j] = "#";
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= target; j++) {
                string tmp = "";
                if (j >= cost[i - 1] && dp[i][j - cost[i - 1]] != "#")
                    tmp = to_string(i) + dp[i][j - cost[i - 1]];
                dp[i][j] = bigger(dp[i-1][j], tmp);          
            }
        }
        return dp[9][target] == "#" ? "0" : dp[9][target];
    }
private:
    string bigger(string& a, string& b) {
        if (a.length() != b.length())
            return a.length() > b.length() ? a : b;
        return a > b ? a : b;
    }
};
class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        map<int, int> mp;
        for (int i = cost.size() - 1; i >= 0; i--) {
            if (mp.count(cost[i]))
                cost[i] = -1;
            else
                mp[cost[i]] = 1;
        }
        vector<vector<string>> dp(9 + 1, vector<string>(target + 1, ""));
        for (int j = 1; j <= target; j++)
            dp[0][j] = "#";
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= target; j++) {
                dp[i][j] = dp[i - 1][j];
                if (cost[i - 1] != -1) {
                    string tmp = "";
                    if (j >= cost[i - 1] && dp[i][j - cost[i - 1]] != "#")
                        tmp = to_string(i) + dp[i][j - cost[i - 1]];
                    dp[i][j] = bigger(dp[i][j], tmp);
                }
            }
        }
        return dp[9][target] == "#" ? "0" : dp[9][target];
    }
private:
    string bigger(string& a, string& b) {
        if (a.length() != b.length())
            return a.length() > b.length() ? a : b;
        return a > b ? a : b;
    }
};
int main() {
    Solution sol;
    vector<int> cost = { 4,3,2,5,6,7,2,5,5 };
    sol.largestNumber(cost, 9);
    return 0;
}