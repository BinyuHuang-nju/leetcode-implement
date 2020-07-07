#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int monotoneIncreasingDigits(int N) {
        string digits = to_string(N);
        int flag = digits.length();
        for (int i = digits.length() - 1; i > 0; i--) {
            if (digits[i] < digits[i - 1]) {
                flag = i - 1;
                digits[i - 1]--;
            }
        }
        int result = 0;
        for (int i = 0; i < digits.size(); i++) {
            if (i <= flag)
                result = result * 10 + (digits[i] - '0');
     /*       else if (i == flag)
                result = result * 10 + (digits[i] - '0' - 1);*/
            else
                result = result * 10 + 9;
        }
        return result;
    }
};