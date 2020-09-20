#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int numSquarefulPerms(vector<int>& A) {
        if (A.size() < 2)
            return 0;
        vector<bool> visited(A.size(), false);
        vector<int> nums;
        sort(A.begin(), A.end());
        int result = 0;
        dfs(result, A, visited, nums);
        return result;
    }
    void dfs(int& result, vector<int>& A, vector<bool>& visited, vector<int> nums) {
        if (nums.size() == A.size()) {
            result++;
            return;
        }
        if (nums.size() == 0) {
            for (int i = 0; i < A.size(); i++) {
                if (i > 0 && A[i] == A[i - 1])
                    continue;
                visited[i] = true;
                nums.push_back(A[i]);
                dfs(result, A, visited, nums);
                nums.pop_back();
                visited[i] = false;
            }
        }
        else {
            for (int i = 0; i < A.size(); i++) {
                if (!visited[i]) {
                    if (i > 0 && A[i] == A[i - 1] && !visited[i - 1])
                        continue;
                    int sq = sqrt(nums[nums.size() - 1] + A[i]);
                    if (sq * sq != nums[nums.size() - 1] + A[i])
                        continue;
                    visited[i] = true;
                    nums.push_back(A[i]);
                    dfs(result, A, visited, nums);
                    nums.pop_back();
                    visited[i] = false;
                }
            }
        }
    }
};