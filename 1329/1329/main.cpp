#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
class Solution1 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<int, vector<int>> mp;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i - j].push_back(mat[i][j]);
            }
        }
        for (map<int, vector<int>>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
            sort(iter->second.begin(), iter->second.end(), [](int& a, int& b) {return a > b; });
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mat[i][j] = mp[i - j].back();
                mp[i - j].pop_back();
            }
        }
        return mat;
    }
};
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        for (int k = 0; k < m; k++) {
            for (int i = 0; i < m - 1; i++) {
                for (int j = 0; j < n - 1; j++) {
                    if (mat[i][j] > mat[i + 1][j + 1])
                        swap(mat[i][j], mat[i + 1][j + 1]);
                }
            }
        }
        return mat;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { { 3,3,1,1 }, { 2,2,1,2 }, { 1,1,1,2 } };
    sol.diagonalSort(a);
    return 0;
}