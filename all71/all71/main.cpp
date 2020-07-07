#include <iostream>
using namespace std;
#include <string>
#include <stack>

class Solution {
public:
    string simplifyPath(string path) {
        if (path.length() == 0 || (path.length() == 1 && path[0] == '/'))
            return "/";

        stack<string> st;
        int i = 0;
        while (i < path.length()) {
            if (path[i] == '/')
                i++;
            else if (path[i] == '.') {
                if (i == path.length() - 1)
                    break;
                int j = i;
                while (j < path.length() && path[j] != '/')
                    j++;
                if (j - i == 1)
                    i++;
                else if (j - i == 2) {
                    if (!st.empty())
                        st.pop();
                    i = i + 2;
                }
                else {
                    st.push(path.substr(i, j - i));
                    i = j;
                }                   
            }
            else {
                int j = i;
                while (j < path.length()) {
                    if (path[j] == '/' || path[j] == '.')
                        break;
                    j++;
                }
                st.push(path.substr(i, j - i));
                i = j;
            }
        }
        if (st.empty())
            return "/";
        string res;
        while (!st.empty()) {
            res = '/' + st.top() + res;
            st.pop();
        }
        return res;
    }
};
int main() {
    Solution sol;
    string a = "/home/";
    a = "/../";
    a = "/home///foo/";
    a = "/a/./b/../../c/";
    cout << sol.simplifyPath(a);
    return 0;
}