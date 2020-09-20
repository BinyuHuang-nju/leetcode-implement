#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>

class Solution1 {  // true but exceeds time limitations 
public:
    int longestWPI(vector<int>& hours) {
        int len = hours.size();
        vector<int> subsum(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            subsum[i] = subsum[i - 1] + (hours[i - 1] > 8 ? 1 : 0);
        }
        int maxlen = 0;
        vector<int> dp(len + 1, 0);
        for (int i = 1; i <= len; i++) {
            for (int j = 1; j <= i; j++) {
                int good = subsum[i] - subsum[j - 1];
                if (2 * good > i - j + 1) {
                    dp[i] = i - j + 1;
                    if (dp[i] > maxlen)
                        maxlen = dp[i];
                    break;
                }
            }
        }
        return maxlen;
    }
};

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int len = hours.size();
        vector<int> subsum(len + 1, 0);
        stack<int> st;
        st.push(0);
        for (int i = 1; i <= len; i++) {
            subsum[i] = subsum[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
            if (subsum[st.top()] > subsum[i])
                st.push(i);
        }
        int maxlen = 0;
        for (int i = len; i >= 1; i--) {
            while (!st.empty() && subsum[st.top()] < subsum[i]) {
                maxlen = max(maxlen, i - st.top());
                st.pop();
            }
        }
        return maxlen;
    }
};

int main() {
    Solution sol;
    vector<int> a = { 9,9,6,0,6,6,9 };
    sol.longestWPI(a);
    return 0;
}