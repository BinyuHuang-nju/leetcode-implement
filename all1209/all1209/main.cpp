#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
private:
    struct Item {
        char present;
        int num;
        Item(char p) :present(p), num(1) {}
    };
public:
    string removeDuplicates(string s, int k) {
        stack<Item> st;
        for (int i = 0; i < s.length(); i++) {
            if (st.empty() || st.top().present != s[i])
                st.push(Item(s[i]));
            else {
                st.top().num++;
                if (st.top().num == k) {
                    st.pop();
                }
            }
        }
        string result = "";
        while (!st.empty()) {
            for (int i = 0; i < st.top().num; i++)
                result = st.top().present + result;
            st.pop();
        }
        return result;
    }
};
int main() {
    Solution sol;
    sol.removeDuplicates("deeedbbcccbdaa", 3);
    return 0;
}