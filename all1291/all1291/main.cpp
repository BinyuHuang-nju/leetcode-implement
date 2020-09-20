#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int inc[10] = { 1,1,11,111,1111,11111,111111,1111111,11111111,111111111 };
        int low_bit = 0, high_bit = 0, tmp_low = low, tmp_high = high;
        long long int init = 0;
        while (tmp_low > 0) {
            low_bit++;
            init = init * 10 + low_bit;
            tmp_low /= 10;
            tmp_high /= 10;
        }
        high_bit = low_bit;
        while (tmp_high > 0) {
            high_bit++;
            tmp_high /= 10;
        }
        vector<int> result;
        for (int bit = low_bit; bit <= high_bit; bit++) {
            int num = init;
            while (num < low && num % 10 !=0)
                num = num + inc[bit];
            while (num % 10 != 0 && num <= high) {
                result.push_back(num);
                num += inc[bit];
            }
            init = init * 10 + bit + 1;
        }
        return result;
    }
};
int main() {
    Solution sol;
    sol.sequentialDigits(8511, 23553);
    return 0;
}