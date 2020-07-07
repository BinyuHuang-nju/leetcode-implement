#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int i = 0, j = len - 1, wid = j - i, hei, size = 0;
        while (i < j) {
            hei = height[i] > height[j] ? height[j] : height[i];
            size = size > (hei * wid) ? size : (hei * wid);
            if (height[i] > height[j])
                j--;
            else
                i++;
            wid--;
        }
        return size;
    }
};
int main() {
    int num;
    vector<int> height;
    cin >> num;
    int temp;
    for (int i = 0; i < num; i++) {
        cin >> temp;
        height.emplace_back(temp);
    }
    Solution sol;
    cout << sol.maxArea(height);
    return 0;
}