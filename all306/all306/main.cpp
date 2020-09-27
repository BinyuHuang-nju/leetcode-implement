#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.length(), bound = n / 2;
        if (n < 3)
            return false;
        vector<long long> results;
        return dfs(num, 0, n, bound, results);
    }
    bool dfs(string num, int start, int n, int bound, vector<long long>& results) {
        if (start == n)
            return results.size() >= 3;
        if (num[start] == '0') {
            if (results.size() < 2) {
                results.push_back(0);
                if (dfs(num, start + 1, n, bound, results))
                    return true;
                results.pop_back();
                return false;
            }
            long long target = results[results.size() - 2] + results[results.size() - 1];
            if(target!=0)
                return false;
            results.push_back(0);
            if (dfs(num, start + 1, n, bound, results))
                return true;
            results.pop_back();
            return false;
        }
        if (results.size() < 2) {
            for (int i = start; i - start < bound && i < n; i++) {
                long long tmp = stoll(num.substr(start, i - start + 1));
                results.push_back(tmp);
                if (dfs(num, i + 1, n, bound, results))
                    return true;
                results.pop_back();
            }
            return false;
        }
        long long target = results[results.size() - 2] + results[results.size() - 1], tmp = 0;
        for (int i = start; i - start < bound && i < n; i++) {
            tmp = tmp * 10 + (num[i] - '0');
            if (tmp == target) {
                results.push_back(tmp);
                if (dfs(num, i + 1, n, bound, results))
                    return true;
                results.pop_back();
            }
            else if (tmp > target)
                return false;
        }
        return false;
    }
};
int main() {
    Solution sol;
    bool x  = sol.isAdditiveNumber("199111992");
    return 0;
}