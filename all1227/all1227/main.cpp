#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        if (n == 1)
            return 1.0;
        if (n == 2)
            return 0.5;
        return (double)1 / n + (double)(n - 2) / n * nthPersonGetsNthSeat(n - 1);
    }
};
int main() {
    Solution sol;
    double x = sol.nthPersonGetsNthSeat(10);
    return 0;
}