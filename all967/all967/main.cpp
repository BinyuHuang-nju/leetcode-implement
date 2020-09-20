#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        if (N == 1)
            return { 0,1,2,3,4,5,6,7,8,9 };
        vector<int> results;
        computeNum(results, N, K, 0, 0);
        return results;
    }
    void computeNum(vector<int>& results, int N, int K, int start, int digit) {
        if (start == N) {
            results.push_back(digit);
            return;
        }
        if (start == 0) {
            for (int i = 1; i < 10; i++) {
                computeNum(results, N, K, 1, i);
            }
        }
        else {
            int tag = digit % 10;
            if (K > 0) {
                if (tag + K <= 9) {
                    computeNum(results, N, K, start + 1, digit * 10 + tag + K);
                }
                if (tag - K >= 0)
                    computeNum(results, N, K, start + 1, digit * 10 + tag - K);
            }
            else 
                computeNum(results, N, K, start + 1, digit * 10 + tag);
        }
    }
};