#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        if (A.size() == 0)
            return 0;
        int len = A.size(), nonPosNum = 0;
        sort(A.begin(), A.end());
        for (nonPosNum = 0; nonPosNum < len; nonPosNum++)
            if (A[nonPosNum] > 0)
                break;
        int sum = 0;
        if (K <= nonPosNum) {
            for (int i = 0; i < K; i++)
                sum -= A[i];
            for (int i = K; i < len; i++)
                sum += A[i];
            return sum;
        }
        for (int i = 0; i < nonPosNum; i++) {
            A[i] = -A[i];
        }
        for (int i = 0; i < len; i++) {
            sum += A[i];
        }
        if ((K - nonPosNum) % 2 == 0)
            return sum;
        int minAbs = A[0];
        for (int i = 1; i < len; i++)
            if (minAbs > A[i])
                minAbs = A[i];
        sum = sum - 2 * minAbs;
        return sum;
    }
};