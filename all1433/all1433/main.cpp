#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        vector<int> nums1(26, 0), nums2(26, 0);
        for (char ch : s1)
            nums1[ch - 'a']++;
        for (char ch : s2)
            nums2[ch - 'a']++;
        return check(nums1, nums2) || check(nums2, nums1);
    }
    bool check(vector<int> nums1, vector<int> nums2) {
        int i = 0, j = 0;
        while (i < 26 && j < 26) {
            while (i < 26 && nums1[i] == 0)
                i++;
            if (i == 26)
                break;
            while (j < 26 && nums2[j] == 0)
                j++;
            if (i > j)
                return false;
            else if (i == j && nums1[i] < nums2[j])
                return false;
            int diff = min(nums1[i], nums2[j]);
            nums1[i] -= diff;
            nums2[j] -= diff;
        }
        return true;
    }
};
int main() {
    Solution sol;
    bool re = sol.checkIfCanBreak("leetcodee", "interview");
    return 0;
}