#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double left = 0.0, right = 1.0, mid;
        int p, q;
        int size = A.size(), count = 0;
        while (1) {
            mid = (left + right) / 2;
            count = 0;
            p = 0;
            for (int i = 0, j = 0; i < size; i++) {
                while (j<size && A[i]>mid* A[j])
                    j++;
                count += size - j;
                if (j < size && p * A[j] < q * A[i]) {
                    p = A[i];
                    q = A[j];
                }
            }
            if (count == K)
                return { p,q };
            else if (count < K)
                left = mid;
            else
                right = mid;
        }
        return { 0,0 };
    }
};