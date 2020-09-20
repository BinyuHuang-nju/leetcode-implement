#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 1;
        while (1) {
            while (i < A.size() && A[i] % 2 == 0)
                i = i + 2;
            while (j < A.size() && A[j] % 2 == 1)
                j = j + 2;
            if (i < A.size() && j < A.size()) {
                swap(A[i], A[j]);
            }
            else
                break;
        }
        return A;
    }
};
int main() {
    vector<int> a = { 4,2,5,7 };
    Solution sol;
    sol.sortArrayByParityII(a);
    return 0;
}