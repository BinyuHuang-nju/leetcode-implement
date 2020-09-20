#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            switch (s[i]) {
            case 'I':if (i + 1 < len && s[i + 1] == 'V') { result += 4; i++; }
                    else if (i + 1 < len && s[i + 1] == 'X') { result += 9; i++; }
                    else result++;
                break;
            case 'V':result += 5; break;
            case 'X':if (i + 1 < len && s[i + 1] == 'L') { result += 40; i++; }
                    else if (i + 1 < len && s[i + 1] == 'C') { result += 90; i++; }
                    else result += 10;
                break;
            case 'L':result += 50; break;
            case 'C':if (i + 1 < len && s[i + 1] == 'D') { result += 400; i++; }
                    else if (i + 1 < len && s[i + 1] == 'M') { result += 900; i++; }
                    else result += 100;
                break;
            case 'D':result += 500; break;
            case 'M':result += 1000; break;
            default:break;
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    sol.romanToInt("MCMXCIV");
    return 0;
}