#include <iostream>
using namespace std;
#include <stack>
#include <map>
#include <vector>

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        map<int,int> st_table;
        int push_index = 0;
        const int len = pushed.size();
        for (int pop_num : popped) {
            while (push_index < len && (st.empty() || !st_table.count(pop_num) || st_table[pop_num] == 0)) {
                st.push(pushed[push_index]);
                st_table[pushed[push_index]] = 1;
                push_index++;
            }
            if (st.top() == pop_num) {
                st.pop();
                st_table[pop_num] = 0;
            }
            else
                return false;
        }
        return true;
    }
};