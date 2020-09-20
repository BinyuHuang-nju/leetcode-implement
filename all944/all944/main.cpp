#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.size() == 0 || A[0].size() == 0)
            return 0;
        int result = 0;
        for (int i = 0; i < A[0].size(); i++) {
            if (notdescendOrder(A, i))
                result++;
        }
        return result;
    }
    bool notdescendOrder(vector<string>& A, int index) {
        int i;
        for (i = 0; i < A.size() - 1; i++)
            if (A[i][index] > A[i + 1][index])
                break;
        if (i == A.size() - 1)
            return false;
        return true;
    }
};