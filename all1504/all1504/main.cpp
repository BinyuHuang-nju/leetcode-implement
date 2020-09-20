#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
class Solution1 {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat.front().size();
        vector<vector<int>> continuity(rows + 1, vector<int>(cols + 1, 0));
        vector<vector<int>> quantity(rows + 1, vector<int>(cols + 1, 0));
        int result = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (mat[i - 1][j - 1] == 0)
                    continue;
                continuity[i][j] = continuity[i - 1][j] + 1;
                int min_height = continuity[i][j];
                for (int k = j; k >= 1; k--) {
                    if (mat[i - 1][k - 1] == 0)
                        break;
                    min_height = min(min_height, continuity[i][k]);
                    quantity[i][j] += min_height;
                }
                result += quantity[i][j];
            }
        }
        return result;
    }
};
class Solution2 {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat.front().size();
        vector<vector<int>> continuity(rows + 1, vector<int>(cols + 1, 0));
        //vector<vector<int>> quantity(rows + 1, vector<int>(cols + 1, 0));
        int result = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (mat[i - 1][j - 1] == 0)
                    continue;
                continuity[i][j] = continuity[i - 1][j] + 1;
                int min_height = continuity[i][j];
                for (int k = j; k >= 1; k--) {
                    if (mat[i - 1][k - 1] == 0)
                        break;
                    min_height = min(min_height, continuity[i][k]);
                    result += min_height;
                }
            }
        }
        return result;
    }
};

class Solution3 {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat.front().size();
        vector<vector<vector<int>>> continuity(rows + 1, vector<vector<int>>(cols + 1, vector<int>(2, 0)));
        //vector<vector<int>> quantity(rows + 1, vector<int>(cols + 1, 0));
        int result = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (mat[i - 1][j - 1] == 0)
                    continue;
                continuity[i][j][0] = continuity[i - 1][j][0] + 1;
                continuity[i][j][1] = continuity[i][j - 1][1] + 1;
                int min_height = continuity[i][j][0];
                for (int k = j; k >= j + 1 - continuity[i][j][1]; k--) {
                    min_height = min(min_height, continuity[i][k][0]);
                    result += min_height;
                }
            }
        }
        return result;
    }
};
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int rows = mat.size(), cols = mat.front().size();
        vector<vector<int>> continuity(rows + 1, vector<int>(cols + 1, 0));
        int result = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                if (mat[i - 1][j - 1] == 0)
                    continue;
                continuity[i][j] = continuity[i - 1][j] + 1;
            }
        }
        for (int i = 1; i <= rows; i++) {
            stack<pair<int, int>> st;
            int sum = 0;
            for (int j = 1; j <= cols; j++) {
                int height = 1;
                while (!st.empty() && st.top().first > continuity[i][j]) {
                    sum = sum - st.top().second * (st.top().first - continuity[i][j]);
                    height += st.top().second;
                    st.pop();
                }
                sum += continuity[i][j];
                result += sum;
                st.push(make_pair(continuity[i][j], height));
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    //vector<vector<int>> a = { {1,0,1},{1,1,0},{1,1,0} };
    vector<vector<int>> a = { {0,1,1,0},{0,1,1,1},{1,1,1,0} };
    sol.numSubmat(a);
    return 0;
}