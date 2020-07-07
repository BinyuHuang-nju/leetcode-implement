#include <iostream>
using namespace std;
#include <vector>

class NumArray {
private:
    vector<int> sums;
public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            sums.push_back(sum);
        }
    }

    int sumRange(int i, int j) {
        if (i == 0)
            return sums[j];
        return sums[j] - sums[i - 1];
    }
};
