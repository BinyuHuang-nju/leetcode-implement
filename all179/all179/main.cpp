#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> digits(nums.size(), "");
        int i;
        for (i = 0; i < nums.size(); i++)
            if (nums[i] != 0)
                break;
        if (i == nums.size())
            return "0";
        for (i = 0; i < nums.size(); i++)
            digits[i] = to_string(nums[i]);
        sort(digits.begin(), digits.end(), my_cmp);
        string res;
        for (i = 0; i < digits.size(); i++)
            res = res + digits[i];
        return res;
    }
private:
    static bool my_cmp(string a, string b) {
        int i;
        for (i = 0; i < a.length() && i < b.length(); i++) {
            if (a[i] < b[i])
                return false;
            else if (a[i] > b[i])
                return true;
        }
        string ab = a + b, ba = b + a;
        return (strcmp(ab.c_str(), ba.c_str())>0);
     /*   int j = i;
        i--;
        if (j < a.length()) {
            for (; j < a.length(); j++) {
                if (a[j] > a[i])
                    return true;
                else if (a[j] < a[i])
                    return false;
            }
        }
        else if (j < b.length()) {
            for (; j < b.length(); j++) {
                if (b[j] > b[i])
                    return false;
                else if (b[j] < b[i])
                    return true;
            }
        }
        return true;*/
    }
};
int main() {
    Solution sol;
  //  cout << to_string(0);
    vector<int> a = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,\
        0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
   // sort(a.begin(), a.end(), cmp);

    cout << sol.largestNumber(a);
    return 0;
}