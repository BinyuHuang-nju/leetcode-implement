#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxSum(vector<int>& nums1, vector<int>& nums2) {
        long long M = 1e9 + 7;
        long long result = 0, sum1 = 0, sum2 = 0;
        int i = 0, j = 0;
        int len1 = nums1.size(), len2 = nums2.size();
        while (i < len1 && j < len2) {
            if (nums1[i] < nums2[j]) {
                sum1 += nums1[i];
                i++;
            }
            else if (nums1[i] > nums2[j]) {
                sum2 += nums2[j];
                j++;
            }
            else {
                result = (result + max(sum1, sum2) + nums1[i]) % M;
                sum1 = sum2 = 0;
                i++;
                j++;
            }
        }
        while (i < len1) {
            sum1 += nums1[i];
            i++;
        }
        while (j < len2) {
            sum2 += nums2[j];
            j++;
        }
        result = (result + max(sum1, sum2)) % M;
        return (int)result;
    }
};
int main() {
    vector<int> n1 = { 2,4,5,8,10 }, n2 = { 4,6,8,9 };
    Solution sol;
    sol.maxSum(n1, n2);
    return 0;
}