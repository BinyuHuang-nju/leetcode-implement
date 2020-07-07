#include <iostream>
using namespace std;
#include <vector>

class Solution_version1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int len1 = matrix.size(), len2 = matrix[0].size();
        int i = len1 - 1, j = 0;
        while (i >= 0 && j < len2) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] > target)
                i--;
            else
                j++;
        }
        return false;
    }
};
class Solution_version2 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        return search(matrix, target, 0, matrix.size() - 1, 0, matrix[0].size() - 1);
    }
private:
    bool search(vector<vector<int>>& matrix, int target, int u, int b, int l, int r) {
        if (u > b || l > r)
            return false;
        if (u == b && l == r)
            return matrix[u][l] == target;
        int mid1 = (u + b) / 2, mid2 = (l + r) / 2;
        if (matrix[mid1][mid2] == target)
            return true;
        else if (matrix[mid1][mid2] > target)
            return search(matrix, target, u, b, l, mid2-1)||search(matrix,target,u,mid1-1,mid2,r);
        return search(matrix, target, u, b, mid2+1, r) || search(matrix, target, mid1+1, b, l, mid2);
    }
};