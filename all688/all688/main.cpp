#include <iostream>
using namespace std;
#include <vector>

class Solution1 {
private:
    // int dir[8][2] = { {-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2} };
    vector<vector<int>> dirs = { {-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2} };
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> knight\
            (N, vector<vector<double>>(N, vector<double>(K + 1, 0)));
        return knightPro(knight, N, K, r, c, K);
    }
    double knightPro(vector<vector<vector<double>>>& knight, \
        int N, int K, int curr, int curc, int curk) {
        if (curr < 0 || curr >= N || curc < 0 || curc >= N)
            return 0.0;
        if (curk == 0)
            return 1.0;
        if (knight[curr][curc][curk] > 1e-6)
            return knight[curr][curc][curk];
        for (vector<int> dir : dirs) {
            knight[curr][curc][curk] += knightPro(knight, N, K, curr + dir[0], curc + dir[1], curk - 1) / 8;
        }
        return knight[curr][curc][curk];
    }
};
class Solution2 {
private:
    // int dir[8][2] = { {-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2} };
    vector<vector<int>> dirs = { {-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2} };
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> knight\
            (K + 1, vector<vector<double>>(N, vector<double>(N, 0)));
        int i, j, k,newi,newj;
        double temp;
        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                knight[0][i][j] = 1.0;
        for (k = 1; k <= K; k++) {
            for (i = 0; i < N; i++) {
                for (j = 0; j < N; j++) {
                    double temp = 0.0;
                    for (vector<int> dir : dirs) {
                        newi = i + dir[0];
                        newj = j + dir[1];
                        if (newi < 0 || newj < 0 || newi >= N || newj >= N)
                            continue;
                        temp = temp + knight[k - 1][newi][newj];
                    }
                    knight[k][i][j] = temp / 8;
                }
            }
        }
        return knight[K][r][c];
    }
};