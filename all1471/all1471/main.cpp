#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int len = arr.size(), mid = (len - 1) / 2;
        int standard = arr[mid];
        vector<int> results;
        int i = 0, j = len - 1, num = 0;
        while (i <= mid && mid <= j && num < k) {
            int pre = standard - arr[i], next = arr[j] - standard;
            if (pre <= next) {
                results.push_back(arr[j]);
                j--;
            }
            else {
                results.push_back(arr[i]);
                i++;
            }
            num++;
        }
        while (num < k) {
            results.push_back(standard);
            num++;
        }
        return results;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 6,7,11,7,6,8 };
    sol.getStrongest(a, 5);
    return 0;
}