#include <iostream>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int diff = 0;
        while (x || y) {
            diff += ((x % 2) ^ (y % 2));
            x = x >>1;
            y = y >>1;
        }
        return diff;
    }
};
int main() {
    Solution sol;
    cout << sol.hammingDistance(1, 4);
    return 0;
}