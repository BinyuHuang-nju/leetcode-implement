#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>
class Solution {
public:
    int balancedStringSplit(string s) {
        int result = 0;
        int l = 0, r = 0;
        for (char ch : s) {
            if (ch == 'L')
                l++;
            else
                r++;
            if (l == r) {
                result++;
                l = 0;
                r = 0;
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    sol.balancedStringSplit("RLLLLRRRLR");
    return 0;
}