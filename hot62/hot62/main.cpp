#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return select_elinear(nums, 0, nums.size() - 1, k);
    }
private:
    int select_elinear(vector<int>& nums, int begin, int end, int k) {
        if (begin == end)
            return nums[begin];
        int q = partition(nums, begin, end);
        int x = q - begin + 1;
        if (k == x)
            return nums[q];
        else if (k < x)
            return select_elinear(nums, begin, q - 1, k);
        return select_elinear(nums, q + 1, end, k - x);
    }
    int partition(vector<int>& nums, int begin, int end) {
        int pivot = nums[end];
        int i = begin, j;
        for(j=begin;j<end;j++)
            if (nums[j] > pivot) {
                swap(nums[i], nums[j]);
                i++;
            }
        swap(nums[i], nums[end]);
        return i;
    }
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
};