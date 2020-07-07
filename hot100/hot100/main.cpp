#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution_version1 {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> count(T.size(), 0);
        if (T.size() < 2)
            return count;
        int i, j, cur_max = T[T.size() - 1];
        for (i = T.size() - 2; i >= 0; i--) {
            if (T[i] < cur_max) {
                if (T[i] < T[i + 1]) {
                    count[i] = 1;
                }
                else {
                    j = i + 1;
                    while (j < T.size() && T[i] >= T[j])
                        j = j + count[j];
                    count[i] = j - i;
                }
            }
            else
                cur_max = T[i];
        }
        return count;
    }
};
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> count(T.size(), 0);
        if (T.size() < 2)
            return count;
        stack<int> st;
        st.push(0);
        for (int i = 1; i < T.size(); i++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                count[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return count;
    }
};