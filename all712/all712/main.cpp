#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int len1 = s1.length(), len2 = s2.length();
        vector<vector<int>> deletesum(len1 + 1, vector<int>(len2 + 1, 0));
        int i, j;
        for (i = 1; i <= len1; i++) {
            deletesum[i][0] = deletesum[i - 1][0] + s1[i - 1];
        }
        for (j = 1; j <= len2; j++) {
            deletesum[0][j] = deletesum[0][j - 1] + s2[j - 1];
        }
        for (i = 1; i <= len1; i++) {
            for (j = 1; j <= len2; j++) {
                deletesum[i][j] = min(deletesum[i - 1][j] + s1[i - 1], deletesum[i][j - 1] + s2[j - 1]);
                if (s1[i - 1] == s2[j - 1])
                    deletesum[i][j] = min(deletesum[i - 1][j - 1], deletesum[i][j]);
                else
                    deletesum[i][j] = min(deletesum[i][j], deletesum[i - 1][j - 1] + s1[i - 1] + s2[j - 1]);
            }
        }
        return deletesum[len1][len2];
    }
private:
    int min(int x, int y) {
        return x < y ? x : y;
    }
};