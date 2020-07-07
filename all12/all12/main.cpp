#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>
class Solution {
public:
    string intToRoman(int num) {
        int base[7] = { 1,5,10,50,100,500,1000 };
        string ch[7] = { "I","V","X","L","C","D","M" };
        string res;
        int cur, c = 6;
        int i;
        while (c >= 0) {
            cur = num / base[c];
            if (cur == 0)
                c--;
            else {
                if ((c == 0 || c == 2 || c == 4) && (cur == 4)) {
                    res = res + ch[c] + ch[c + 1];
                    num = num - (base[c] * 4);
                    c--;
                }
                else if ((c == 1 || c == 3 || c == 5) && cur == 1 && num >= base[c] + 4 * base[c - 1]) {
                    res = res + ch[c - 1] + ch[c + 1];
                    num = num - base[c] - 4 * base[c - 1];
                    c = c - 2;
                }
                else {
                    for (i = 0; i < cur; i++)
                        res = res + ch[c];
                    num = num - (base[c] * cur);
                    c--;
                }

            }
        }
        return res;
    }
};
int main() {
    Solution sol;
    cout << sol.intToRoman(1994);
    return 0;
}