#include <iostream>
using namespace std;
#include <vector>
#include <set>
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        int max = 0, cur = 1;
        for (int num : nums) {
            if (!st.count(num - 1)) {
                cur = 1;
                while (st.count(num + 1)) {
                    num++;
                    cur++;
                }
                max = max > cur ? max : cur;
            }
        }
        return max;
    }
};