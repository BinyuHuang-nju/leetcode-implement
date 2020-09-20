#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int remain0 = upper, remain1 = lower;
        vector<vector<int>> tmp;
        vector<vector<int>> result(2, vector<int>(colsum.size(), 0));
        for (int i = 0; i < colsum.size(); i++) {
            if (colsum[i] == 2) {
                if (remain0 == 0 || remain1 == 0)
                    return tmp;
                result[0][i] = result[1][i] = 1;
                remain0--;
                remain1--;
            }
            else if (colsum[i] == 1) {
                if (remain0 == 0 && remain1 == 0)
                    return tmp;
                if (remain0 >= remain1) {
                    result[0][i] = 1;
                    remain0--;
                }
                else {
                    result[1][i] = 1;
                    remain1--;
                }
            }
        }
        if (remain0 > 0 || remain1 > 0)
            return tmp;
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> a = {2,2,1,1 };
    sol.reconstructMatrix(2,3, a);
    return 0;
}