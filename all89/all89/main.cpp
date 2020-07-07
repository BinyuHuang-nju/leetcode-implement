#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    vector<int> grayCode(int n) {
        if (n == 0)
            return { 0 };
        if (n == 1)
            return { 0,1 };
        if (n == 2)
            return { 0,1,3,2 };
        vector<int> res = { 0,1,3,2 };
        int i, j, pow = 4;
        for (i = 3; i <= n; i++) {
            for (j = res.size() - 1; j >= 0; j--)
                res.push_back(res[j] + pow);

            pow = pow * 2;
        }
        return res;
    }
};