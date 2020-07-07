#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int edge1 = 0, edge2 = matrix.size() - 1;
        int i = 0, j = matrix.size()-1;
        int temp;
        for (; edge1 < edge2; edge1++, edge2--) {
            i = edge1;
            j = edge2;
            for (; i < edge2; i++, j--) {
                temp = matrix[edge1][i];
                matrix[edge1][i] = matrix[j][edge1];
                matrix[j][edge1] = matrix[edge2][j];
                matrix[edge2][j] = matrix[i][edge2];
                matrix[i][edge2] = temp;
            }
        }
    }
};

int main() {
    vector<vector<int>> matrix = { {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
    Solution sol;
    sol.rotate(matrix);
    return 0;
}