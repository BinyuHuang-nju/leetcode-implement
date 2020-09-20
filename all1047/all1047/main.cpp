#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>

class Solution1 {
public:
    string removeDuplicates(string S) {
        string result = S;
        bool remain = true;
        while (remain) {
            string temp = "";
            int i = 0;
            while (i < result.length()) {
                if (i + 1 < result.length() && result[i] == result[i + 1])
                    i = i + 2;
                else {
                    temp += result[i];
                    i++;
                }
            }
            if (result.length() == temp.length())
                remain = false;
            else
                result = temp;
        }
        return result;
    }
};

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char ch : S) {
            if (st.empty() || st.top() != ch)
                st.push(ch);
            else
                st.pop();
        }
        if (st.empty())
            return "";
        string temp = "";
        while (!st.empty()) {
            temp += st.top();
            st.pop();
        }
        string result = "";
        for (int i = temp.length() - 1; i >= 0; i--)
            result += temp[i];
        return result;
    }
};

int main() {
    Solution sol;
    sol.removeDuplicates("abbaca");
    return 0;
}