#include <iostream>
using namespace std;
#include<vector>
#include <map>

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> hash1, hash2;
        int i;
        for (i = 0; i < nums1.size(); i++)
            if (!hash1.count(nums1[i]))
                hash1[nums1[i]] = 1;
        for (i = 0; i < nums2.size(); i++)
            if (!hash2.count(nums2[i]))
                hash2[nums2[i]] = 1;
        vector<int> res;
        map<int, int>::iterator iter;
        for (iter = hash1.begin(); iter != hash1.end(); iter++) {
            if (hash2.count(iter->first))
                res.push_back(iter->first);
        }
        return res;
    }
};