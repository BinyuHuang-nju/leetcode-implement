#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3)
            return 0;
        int diff = A[1] - A[0], cur_diff, len = 2, i;
        int res = 0;
        for (i = 2; i < A.size(); i++) {
            cur_diff = A[i] - A[i-1];
            if (cur_diff == diff)
                len++;
            else {
                if (len > 2)
                    res = res + sum(len);
                diff = cur_diff;
                len = 2;
            }
        }
        if (len > 2)
            res = res + sum(len);
        return res;
    }
    int sum(int n) {
        int res = 0;
        for (int i = 1; i <= n - 2; i++)
            res += i;
        return res;
    }
};
int main() {
    vector<int> A = { 1,2,3,8,9,10 };
    Solution sol;
    cout << sol.numberOfArithmeticSlices(A);
    return 0;
}