#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    bool isNumber(string s) {
        bool have_base_sign = false, have_exp_sign = false, have_base_num_point = false;
        bool enter_exp = false, enter_base_num = false, enter_exp_num = false;
        bool enter_last_space = false;
        int i = 0, len = s.length();
        if (len == 1)
            return (s[0] >= '0' && s[0] <= '9');
        if (s[len - 1] == 'e')
            return false;
        while (i < len && s[i] == ' ')
            i++;
        for (; i < len; i++) {
            if (s[i] == '+' || s[i] == '-') {
                if (have_base_sign || enter_base_num|| enter_last_space||have_base_num_point)
                    return false;
                have_base_sign = true;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                if (enter_last_space)
                    return false;
                enter_base_num = true;
            }
            else if (s[i] == '.') {
                if (have_base_num_point|| enter_last_space)
                    return false;
                have_base_num_point = true;
            }
            else if (s[i] == 'e') {
                if (i == 0 || !enter_base_num|| enter_last_space)
                    return false;
                enter_exp = true;
                break;
            }
            else if (s[i] == ' ') {
                enter_last_space = true;
            }
            else
                return false;
        }
        if (!enter_exp)
            return enter_base_num;
        i++;
        if (i >= len)
            return false;
        for (; i < len; i++) {
            if (s[i] == '+' || s[i] == '-') {
                if (have_exp_sign || enter_exp_num|| enter_last_space)
                    return false;
                have_exp_sign = true;
            }
            else if (s[i] >= '0' && s[i] <= '9') {
                if (enter_last_space)
                    return false;
                enter_exp_num = true;
            }
            else if (s[i] == ' ') {
                enter_last_space = true;
            }
            else
                return false;
        }
        return enter_exp_num;
    }
};
int main() {
    Solution sol;
    //bool x = sol.isNumber("53.5e93");
    //bool x = sol.isNumber("+-3");
    //bool x = sol.isNumber("95a54e53"); 
    //bool x = sol.isNumber("1 ");
    //bool x = sol.isNumber(" .");
    //bool x = sol.isNumber("3 .");
    //bool x = sol.isNumber("1  ");
    //bool x = sol.isNumber("0e ");
    bool x = sol.isNumber(".-4");
    return 0;
    float y = 46.e3;
}