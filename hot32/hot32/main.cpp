#include <iostream>
using namespace std;
#include <string>

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length())
            return "";
        if (t.length() == 0)
            return "";
        int left = 0, right = -1, lb = -1, rb = s.length() + 1;
        int sFreq[64] = { 0 }, tFreq[64] = { 0 };
        int i;
        for (i = 0; i < t.length(); i++)
            tFreq[t[i] - 'A']++;
        while (left + t.size() <= s.size()) {
            if (right - left + 1 < (int)t.length()) {
                if (right < (int)s.length() - 1) {
                    right++;
                    sFreq[s[right] - 'A']++;
                }
                else
                    break;
            }
            else if (right - left + 1 == t.length()) {
                i = 0;
                while (i < 64) {
                    if (sFreq[i] < tFreq[i])
                        break;
                    i++;
                }
                if (i < 64) {
                    if (right < (int)s.length() - 1) {
                        right++;
                        sFreq[s[right] - 'A']++;
                    }
                    else
                        break;
                }
                else
                    return s.substr(left, right - left + 1);
            }
            else {
                i = 0;
                while (i < 64) {
                    if (sFreq[i] < tFreq[i])
                        break;
                    i++;
                }
                if (i < 64) {
                    if (right < (int)s.length() - 1) {
                        right++;
                        sFreq[s[right] - 'A']++;
                    }
                    else
                        break;
                }
                else {
                    if (right - left < rb - lb) {
                        lb = left;
                        rb = right;
                    }
                    sFreq[s[left] - 'A']--;
                    left++;
                }
            }
        }
        return lb == -1 ? "" : s.substr(lb, rb - lb + 1);
    }
};
int main() {
    //string s = "ADOBEBANC", t = "ABC"; pass
    string s = "ABC", t = "B";
    Solution sol;
    cout << sol.minWindow(s, t);
    return 0;
}