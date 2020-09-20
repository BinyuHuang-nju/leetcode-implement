#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    string getHappyString(int n, int k) {
        string result = "";
        int seq = 1;
        dfs(result, "", 0, n, seq, k);
        return result;
    }
    void dfs(string& result, string cur, int start, int n, int& seq, int k) {
        if (seq > k)
            return;
        if (start == n) {
            if (seq == k)
                result = cur;
            seq++;
            return;
        }
        if (start == 0) {
            for (int i = 0; i < 3; i++) {
                cur.push_back('a' + i);
                dfs(result, cur, 1, n, seq, k);
                cur.pop_back();
            }
        }
        else {
            for (int i = 0; i < 3; i++) {
                if (i == cur.back()-'a')
                    continue;
                cur.push_back('a' + i);
                dfs(result, cur, start + 1, n, seq, k);
                cur.pop_back();
            }
        }
    }
};
int main() {
    Solution sol;
    sol.getHappyString(10, 100);
    return 0;
}