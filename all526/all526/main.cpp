#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N, 0);
        for (int i = 0; i < N; i++)
            nums[i] = i + 1;
        int res = 0;
        dfs(res, nums, N, 0);
        return res;
    }
    void dfs(int& res, vector<int>& nums, int N, int begin) {
        if (begin >= N)
            res++;
        else {
            for (int i = begin; i < N; i++) {
                if (nums[i] % (begin + 1) == 0 || (begin + 1) % nums[i] == 0) {
                    swap(nums[begin], nums[i]);
                    dfs(res, nums, N, begin + 1);
                    swap(nums[begin], nums[i]);
                }
            }
        }
    }
};