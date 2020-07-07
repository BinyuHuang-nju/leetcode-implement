#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        int maxProduct = nums[0], product = 1;
        int i, len = nums.size();
        for (i = 0; i < len; i++) {
            product = product * nums[i];
            if (maxProduct < product)
                maxProduct = product;
            if (nums[i] == 0)
                product = 1;
        }
        product = 1;
        for (i = len - 1; i >= 0; i--) {
            product = product * nums[i];
            if (maxProduct < product)
                maxProduct = product;
            if (nums[i] == 0)
                product = 1;
        }
        return maxProduct;
    }
};