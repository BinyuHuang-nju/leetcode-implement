#include <iostream>
using namespace std;
#include <vector>
/*执行用时 :
4 ms
, 在所有 C++ 提交中击败了
99.58 %
的用户
内存消耗 :
13.3 MB
, 在所有 C++ 提交中击败了
5.07 %
的用户*/
class Solution_version1 {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return -1;
        int n = nums.size() - 1;
        int* dp = new int[n];
        memset(dp, 0, sizeof(int) * n);
        int i;
        for (i = 0; i < nums.size(); i++) {
            dp[nums[i] - 1]++;
            if (dp[nums[i] - 1] > 1)
                return nums[i];
        }
        return -1;
    }
};
// exist fault
class Solution_version2 {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 1)
            return -1;
        int n = nums.size() - 1;
        double pro = 1, cur = 1;
        int i;
        for (i = 1; i <= n; i++)
            pro = pro * i;
        for (i = 0; i < nums.size(); i++)
            cur = cur * nums[i];
        return (int)cur / pro;
    }
};