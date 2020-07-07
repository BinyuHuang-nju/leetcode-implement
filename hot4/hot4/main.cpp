#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        int len = len1 + len2;
        int* re = new int[len];
        int i = 0, j = 0, k = 0;
        while (i < len1 && j < len2) {
            if (nums1[i] <= nums2[j]) {
                re[k++] = nums1[i++];
            }
            else
                re[k++] = nums2[j++];
        }
        while(i<len1)
            re[k++] = nums1[i++];
        while(j<len2)
            re[k++] = nums2[j++];
        double mid;
        if (len % 2 == 0)
            mid = ((double)re[len / 2 - 1] + re[len / 2]) / 2;
        else
            mid = (double)re[len / 2];
        delete[]re;
        return mid;
    }
};
int main() {
    Solution sol;
    vector<int> nums1, nums2;
    int n1, n2, temp;
    cin >> n1 >> n2;
    for (int i = 0; i < n1; i++)
    {
        cin >> temp;
        nums1.emplace_back(temp);
    }
    for (int i = 0; i < n2; i++) {
        cin >> temp;
        nums2.emplace_back(temp);
    }
    cout<<sol.findMedianSortedArrays(nums1, nums2);
    
    return 0;
}