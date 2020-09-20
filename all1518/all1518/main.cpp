#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int result = numBottles, remain = numBottles;
        while (remain >= numExchange) {
            int change = remain / numExchange;
            result += change;
            remain = remain - change * (numExchange - 1);
        }
        return result;
    }
};
int main() {
    Solution sol;
    sol.numWaterBottles(9, 3);
    return 0;
}