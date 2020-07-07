#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        if (arr.size() <= k)
            return arr;
        select_elinear(arr, 0, arr.size() - 1, k);
        vector<int> results;
        for (int i = 0; i < k; i++)
            results.push_back(arr[i]);
        return results;
    }
    void select_elinear(vector<int>& arr, int p, int r, int k) {
        if (p == r)
            return;
        int q = partition(arr, p, r);
        int x = q - p + 1;
        if (x == k)
            return;
        else if (x < k)
            select_elinear(arr, q + 1, r, k - x);
        else
            select_elinear(arr, p, q - 1, k);
    }
    int partition(vector<int>& arr, int p, int r) {
        int pivot = arr[r];
        int i = p;
        for (int j = p; j < r; j++) {
            if (arr[j] < pivot) {
                swap(arr[i], arr[j]);
                i++;
            }
        }
        swap(arr[i], arr[r]);
        return i;
    }
    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }
};
int main() {
    vector<int> arr = { 1,3,5,7,2,4,6,8 };
    Solution sol;
    vector<int> re = sol.smallestK(arr, 4);
    return 0;
}