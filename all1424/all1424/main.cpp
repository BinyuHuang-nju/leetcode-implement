#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int mx = 0;
        for (int i = 0; i < nums.size(); i++)
            mx = max(mx, i + (int)nums[i].size());
        vector<stack<int>> sts(mx);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[i].size(); j++) {
                sts[i + j].push(nums[i][j]);
            }
        }
        vector<int> results;
        for (stack<int> st : sts) {
            while (!st.empty()) {
                results.push_back(st.top());
                st.pop();
            }
        }
        return results;
    }
};
int main() {
    vector<vector<int>> a = { {1,2,3,4,5},{6,7},{8},{9,10,11},{12,13,14,15,16} };
    Solution sol;
    sol.findDiagonalOrder(a);
    return 0;
}