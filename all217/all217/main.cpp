#include <iostream>
using namespace std;
#include <vector>
#include <map>
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            if (hash.count(nums[i]))
                return true;
            hash[nums[i]] = 1;
        }
        return false;
    }
};