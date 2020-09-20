#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int len = A.size();
        if (len < 2)
            return 0;
        vector<int> C(A);
        for (int b : B)
            C.push_back(b);
        int count = 1, k = C[0];
        for (int i = 1; i < 2 * len; i++) {
            if (count == 0)
                k = C[i];
            if (k == C[i])
                count++;
            else
                count--;
        }
        int count1 = 0, count2 = 0;
        for (int i = 0; i < len; i++) {
            if (A[i] == k)
                count1++;
            if (B[i] == k)
                count2++;
            if (A[i] != k && B[i] != k)
                return -1;
        }
        count = count1 + count2;
        if (count < len)
            return -1;
        return count1 > count2 ? (len - count1) : (len - count2);
    }
};