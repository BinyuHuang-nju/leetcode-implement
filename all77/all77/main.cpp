#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        vector<int> temp;
        backtrace(results, temp, n, k, 1);
        return results;
    }
    void backtrace(vector<vector<int>>& results, vector<int>& temp, int n, int k, int begin) {
        if (temp.size() == k) {
            results.push_back(temp);
            return;
        }
        int m = n + 1 - k + temp.size();
        for (int i = begin; i <= m; i++) {
            temp.push_back(i);
            backtrace(results, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
};
int main() {
    Solution sol;
    sol.combine(5, 3);
    return 0;
}