#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), i, j;
        if (len <= 2)
            return 0;
        int* leftmax = new int[len];
        int* rightmax = new int[len];
        leftmax[0] = 0;
        rightmax[len - 1] = 0;
        int curmax = height[0];
        for (i = 1; i < len; i++) {
            curmax = curmax > height[i] ? curmax : height[i];
            leftmax[i] = curmax;
        }
        curmax = height[len - 1];
        for (j = len - 2; j >= 0; j--) {
            curmax = curmax > height[j] ? curmax : height[j];
            rightmax[j] = curmax;
        }
        int sum = 0;
        int maxmin;
        for (i = 1; i < len - 1; i++) {
            maxmin = leftmax[i] > rightmax[i] ? rightmax[i] : leftmax[i];
            if (maxmin > height[i])
                sum += (maxmin - height[i]);
        }
        delete[]leftmax;
        delete[]rightmax;
        return sum;
    }
};
int main() {
    vector<int> height = { 0,1,0,2,1,0,1,3,2,1,2,1 };
    Solution sol;
    cout << sol.trap(height);
    return 0;
}