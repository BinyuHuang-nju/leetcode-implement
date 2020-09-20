#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <bitset>
class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size();
        vector<vector<int>> memo(m + 1, vector<int>(1 << n, 0));
        for (int row = 1; row <= m; row++) {
            for (int state = 0; state < (1 << n); state++) {
                bitset<8> bs(state);
                bool safe_state = true;
                for (int i = 0; i < n; i++) {
                    if ((seats[row - 1][i] == '#' && bs[i]) || (i < n - 1 && bs[i] && bs[i + 1])) {
                        safe_state = false;
                        break;
                    }
                }
                if (!safe_state) {
                    memo[row][state] = -1;
                    continue;
                }
                for (int last_state = 0; last_state < (1 << n); last_state++) {
                    if (memo[row - 1][last_state] == -1)
                        continue;
                    bitset<8> last_bs(last_state);
                    bool safe = true;
                    for (int i = 0; i < n; i++) {
                        if (last_bs[i] && ((i > 0 && bs[i - 1]) || (i < n - 1 && bs[i + 1]))) {
                            safe = false;
                            break;
                        }
                    }
                    if (safe)
                        memo[row][state] = max(memo[row][state], memo[row - 1][last_state] + (int)bs.count());
                }
            }
        }
        int result = 0;
        for (int i = 0; i < (1 << n); i++)
            result = max(result, memo[m][i]);
        return result;
    }
};
int main() {
    Solution sol;
    /*vector<vector<char>> a = { {'.','.','.','.','#','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','#','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','#','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','#','.','.','#','.'} };*/
    vector<vector<char>> a = { {'.','.','.','.','.','.','.','.'},
            {'.','#','.','.','.','.','.','.'},
            {'.','.','#','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'},
            {'.','.','.','#','.','.','.','.'},
            {'.','.','.','.','.','#','.','.'},
            {'.','#','.','.','.','.','.','.'},
            {'.','.','.','.','.','.','.','.'} };
    vector<vector<char>> b = { {'#','.','#','#','.','#'},
                {'.','#','#','#','#','.'},
                {'#','.','#','#','.','#'} };
    sol.maxStudents(b);
    return 0;
}