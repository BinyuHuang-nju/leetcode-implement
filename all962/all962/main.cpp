#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        stack<int> decst;
        for (int i = 0; i < A.size(); i++) {
            if (decst.empty() || A[decst.top()] > A[i])
                decst.push(i);
        }
        int maxlen = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
            while (!decst.empty() && A[decst.top()] <= A[i]) {
                maxlen = max(maxlen, i - decst.top());
                decst.pop();
            }
        }
        return maxlen;
    }
};
int main() {
    vector<int> a = { 6,0,8,2,1,5 };
    Solution sol;
    sol.maxWidthRamp(a);
    return 0;
}