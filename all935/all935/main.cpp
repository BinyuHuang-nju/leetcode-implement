#include <iostream>
using namespace std;
#include <vector>

class Solution1 {
public:
    int knightDialer(int N) {
        vector<vector<long long unsigned int>> seqs(N, vector<long long unsigned>(10, 1));
        for (int i = 1; i < N; i++) {
            seqs[i][0] = seqs[i - 1][4] + seqs[i - 1][6];
            seqs[i][1] = seqs[i - 1][6] + seqs[i - 1][8];
            seqs[i][2] = seqs[i - 1][7] + seqs[i - 1][9];
            seqs[i][3] = seqs[i - 1][4] + seqs[i - 1][8];
            seqs[i][4] = seqs[i - 1][0] + seqs[i - 1][3] + seqs[i - 1][9];
            seqs[i][5] = 0;
            seqs[i][6] = seqs[i - 1][0] + seqs[i - 1][1] + seqs[i - 1][7];
            seqs[i][7] = seqs[i - 1][2] + seqs[i - 1][6];
            seqs[i][8] = seqs[i - 1][1] + seqs[i - 1][3];
            seqs[i][9] = seqs[i - 1][2] + seqs[i - 1][4];
        }
        long long unsigned int result = 0;
        for (int i = 0; i < 10; i++)
            result += seqs[N - 1][i];
        return result % 1000000007;
    }
};

class Solution {
public:
    int knightDialer(int N) {
        vector<vector<long long>> seqs(N, vector<long long>(10, 1));
        for (int i = 1; i < N; i++) {
            seqs[i][0] = (seqs[i - 1][4] + seqs[i - 1][6]) % 1000000007;
            seqs[i][1] = (seqs[i - 1][6] + seqs[i - 1][8]) % 1000000007;
            seqs[i][2] = (seqs[i - 1][7] + seqs[i - 1][9]) % 1000000007;
            seqs[i][3] = (seqs[i - 1][4] + seqs[i - 1][8]) % 1000000007;
            seqs[i][4] = (seqs[i - 1][0] + seqs[i - 1][3] + seqs[i - 1][9]) % 1000000007;
            seqs[i][5] = 0;
            seqs[i][6] = (seqs[i - 1][0] + seqs[i - 1][1] + seqs[i - 1][7]) % 1000000007;
            seqs[i][7] = (seqs[i - 1][2] + seqs[i - 1][6]) % 1000000007;
            seqs[i][8] = (seqs[i - 1][1] + seqs[i - 1][3]) % 1000000007;
            seqs[i][9] = (seqs[i - 1][2] + seqs[i - 1][4]) % 1000000007;
        }
        long long int result = 0;
        for (int i = 0; i < 10; i++)
            result += seqs[N - 1][i];
        return result % 1000000007;
    }
};