#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return 0;
        bool negative = false;
        if (x < 0) {
            negative = true;
            if (x == -2147483648)
                return 0;
            x = -x;
        }
        unsigned int res = 0;
        int c;
        while (x > 0) {
            c = x % 10;
            x = x / 10;
            if (res > 214748364 || (res == 2147483647 && c > 7))
                return 0;
            res = res * 10 + c;
        }
        int ret = (int)res;
        if (negative)
            ret = -(int)res;
        return ret;
    }
};
int main() {
    //int x = -123456780;
    int x = 1534236469;
    Solution sol;
    cout << sol.reverse(x);
    return 0;
}