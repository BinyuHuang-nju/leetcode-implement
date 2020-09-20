#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n - 1]++;
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 10)
                return digits;
            digits[i] = 0;
            if (i != 0) {
                digits[i - 1]++;
            }
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 7,8,9,9 };
    vector<int> b = sol.plusOne(a);
    return 0;
}