#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int countVowelPermutation(int n) {
        const int M = 1000000007;
        long long int a = 1, e = 1, i = 1, o = 1, u = 1;
        long long int tmp_a, tmp_e, tmp_i, tmp_o, tmp_u;
        for (int k = 2; k <= n; k++) {
            tmp_a = (e + i + u) % M;
            tmp_e = (a + i) % M;
            tmp_i = (e + o) % M;
            tmp_o = i;
            tmp_u = (i + o) % M;
            a = tmp_a;
            e = tmp_e;
            i = tmp_i;
            o = tmp_o;
            u = tmp_u;
        }
        return (a + e + i + o + u) % M;
    }
};
int main() {
    Solution sol;
    sol.countVowelPermutation(2);
    return 0;
}