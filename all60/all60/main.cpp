#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    string getPermutation(int n, int k) {
        int* fac = new int[n + 1];
        vector<char> chs;
        string res;
        int i, fact = 1, index;
        fac[0] = 1;
        for (i = 1; i <= n; i++) {
            fact = fact * i;
            fac[i] = fact;
            chs.push_back((char)('0' + i));
        }
        k = k - 1;
        for (i = n - 1; i >= 0; i--) {
            index = k / fac[i];
            res = res + chs[index];
            chs.erase(chs.begin() + index);
            k = k - fac[i] * index;
        }
        return res;
    }
};