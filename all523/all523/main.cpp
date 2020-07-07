#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if (nums.size() < 2)
            return false;
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == 0 && nums[i + 1] == 0)
                return true;
        if (k == 0)
            return false;
        if (k < 0)
            k = -k;
        int* submod = new int[nums.size()];
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            submod[i] = sum % k;
            if (i > 0 && submod[i] == 0)
                return true;
            for (int j = 0; j < i - 1; j++)
                if (submod[i] == submod[j])
                    return true;
        }
        delete[]submod;
        return false;
    }
};
int main() {
    vector<int> a = { 0,1,0,3,0,4,0,4,0 };
    Solution sol;
    cout << sol.checkSubarraySum(a, 5);
    return 0;
}