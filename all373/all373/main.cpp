#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> results;
        if (nums1.size() * nums2.size() <= k) {
            for (int i = 0; i < nums1.size(); i++)
                for (int j = 0; j < nums2.size(); j++)
                    results.push_back({ nums1[i],nums2[j] });
            return results;
        }
        vector<int> steps(nums1.size(), 0);
        for (int i = 0; i < k; i++) {
            int minStep = 0, min = INT_MAX;
            for (int j = 0; j < nums1.size(); j++) {
                if (steps[j] < nums2.size() && nums1[j] + nums2[steps[j]] < min) {
                    min = nums1[j] + nums2[steps[j]];
                    minStep = j;
                }
            }
            results.push_back({ nums1[minStep],nums2[steps[minStep]] });
            steps[minStep]++;
        }
        return results;
    }
};