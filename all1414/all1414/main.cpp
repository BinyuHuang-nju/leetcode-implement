#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fib = { 1,1 };
        int a = 1, b = 1;
        while (a + b <= k) {
            fib.push_back(a + b);
            b = a + b;
            a = b - a;
        }
        int result = 0;
        for (int i = fib.size() - 1; i >= 0; i--) {
            if (k >= fib[i]) {
                result++;
                k = k - fib[i];
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    sol.findMinFibonacciNumbers(19);
    return 0;
}