#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

class Solution1 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int i = 0, j = 0;
        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] == nums2[j]) {
                res.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
                i++;
            else
                j++;
        }
        return res;
    }
};
class Solution2 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> hash1, hash2;
        int i;
        for (i = 0; i < nums1.size(); i++)
            hash1[nums1[i]] ++;
        for (i = 0; i < nums2.size(); i++)
            hash2[nums2[i]]++;
        vector<int> res;
        int min = 0;
        map<int, int>::iterator iter;
        for (iter = hash1.begin(); iter != hash1.end(); iter++) {
            if (hash2.count(iter->first)) {
                min = iter->second < hash2[iter->first] ? iter->second : hash2[iter->first];
                for(i=0;i<min;i++)
                    res.push_back(iter->first);
            }
        }
        return res;
    }
};