#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pro = 1, i;
        vector<int> res;
        bool existZero = false;
        int firstExistZero = -1;
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] == 0 && firstExistZero==-1) {
                existZero = true;
                firstExistZero = i;
            }
            else
                pro = pro * nums[i];
        }
        if (existZero) {
            int j;
            for (j = 0; j < firstExistZero; j++)
                res.push_back(0);
            res.push_back(pro);
            for (j = firstExistZero + 1; j < nums.size(); j++)
                res.push_back(0);
            return res;
        }
        pro = pro / nums[0];
        res.push_back(pro);
        for (i = 1; i < nums.size(); i++) {
            pro = pro / nums[i] * nums[i - 1];
            res.push_back(pro);
        }
        return res;
    }
};