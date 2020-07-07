#include <iostream>
using namespace std;
#include <vector>

class Solution1 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i, j;
        for (i = triangle.size() - 2; i >= 0; i--) {
            for (j = 0; j < triangle[i].size(); j++) {
                triangle[i][j] = triangle[i][j] + min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
    int min(int x, int y) {
        return x < y ? x : y;
    }
};

class Solution2 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int i, j;
        vector<vector<int>> path(triangle.size(), vector<int>(triangle.size(), 0));
        path[0][0] = triangle[0][0];
        for (i = 1; i < triangle.size(); i++) {
            path[i][0] = path[i - 1][0] + triangle[i][0];
            for (j = 1; j < i; j++) {
                path[i][j] = min(path[i - 1][j - 1], path[i - 1][j]) + triangle[i][j];
            }
            path[i][i] = path[i - 1][i - 1] + triangle[i][i];
        }
        int res = path[triangle.size() - 1][0];
        for (i = 1; i < triangle.size(); i++)
            res = min(res, path[triangle.size() - 1][i]);
        return res;
    }
    int min(int x, int y) {
        return x < y ? x : y;
    }
};