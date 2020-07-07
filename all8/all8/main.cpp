#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int myAtoi(string str) {
        int index = 0;
        while (index < str.length() && str[index] == ' ')
            index++;
        if (index == str.length())
            return 0;
        bool sign = true;
        long long res = 0;
        if (str[index] == '-') {
            sign = false;
            index++;
        }
        else if (str[index] == '+')
            index++;
        else if (!(str[index] >= '0' && str[index] <= '9'))
            return 0;
        while (index < str.length() && str[index] >= '0' && str[index] <= '9') {
            res = res * 10 + (long long)(str[index] - '0');
            if (res >= 2147483648) {
                if (!sign)
                    return INT_MIN;
                return INT_MAX;
            }
            index++;
        }
        if (!sign)
            return (int)(-res);
        return (int)res;
    }
};
int main() {
    Solution sol;
    cout << sol.myAtoi("42");
    return 0;
}