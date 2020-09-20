#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        if (N < 1)
            return -1;
        vector<vector<bool>> watch(N + 1, vector<bool>(N + 1, false));
        for (vector<int> t : trust)
            watch[t[0]][t[1]] = true;
        int i = 1, j = 2;
        while (j <= N) {
            if (watch[i][j])
                i = j;
            j++;
        }
        for (int k = 1; k <= N; k++)
            if (k != i && (watch[i][k] || !watch[k][i]))
                return -1;
        return i;
    }
};