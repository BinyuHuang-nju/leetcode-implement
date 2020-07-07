#include <iostream>
using namespace std;
#include <string>
#include <stack>
#include <cstring>

class Solution {
public:
    string decodeString(string s) {
        if (s.length() == 0)
            return "";
        stack<string> st;
        string temp, record, rec;
        int times = 1, cur = 0, res, i, j;
        for (i = 0; i < s.length(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                cur = cur * times + (s[i] - '0');
                times = 10;
            }
            else if (s[i] == '[') {
                st.push(to_string(cur));
                times = 1;
                cur = 0;
                st.push("[");
            }
            else if (s[i] == ']') {
                record.clear();
                rec.clear();
                while (!st.empty() && st.top() != "[") {
                    record = st.top() + record;
                    st.pop();
                }
                st.pop();
                res = atoi(st.top().c_str());
                st.pop();
                for (j = 0; j < res; j++)
                    rec = rec + record;
                st.push(rec);
            }
            else {
                temp = s[i];
                st.push(temp);
            }
        }
        //stack<string> ret;
        string str;
        while (!st.empty()) {
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};
int main() {
    Solution sol;
    //string s = "3[a]10[bc]";//pass
    //string s = "3[a2[c]]";  //pass
    string s = "2[abc]3[cd]ef"; //pass
    cout << sol.decodeString(s);
    return 0;
}