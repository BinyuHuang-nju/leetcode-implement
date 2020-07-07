#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <cstring>

class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.length() == 0)
            return word2.length();
        if (word2.length() == 0)
            return word1.length();
        vector<vector<int>> minDist(word1.length() + 1, vector<int>(word2.length() + 1, 0));
        int i, j;
        for (i = 0; i <= word1.length(); i++)
            minDist[i][0] = i;
        for (j = 0; j <= word2.length(); j++)
            minDist[0][j] = j;
        for (i = 1; i <= word1.length(); i++) {
            for (j = 1; j <= word2.length(); j++) {
                minDist[i][j] = min(minDist[i][j - 1], minDist[i - 1][j]) + 1;
                if (word1[i - 1] == word2[j - 1])
                    minDist[i][j] = min(minDist[i - 1][j - 1], minDist[i][j]);
                else
                    minDist[i][j] = min(minDist[i - 1][j - 1] + 1, minDist[i][j]);
            }
        }
        return minDist[word1.length()][word2.length()];
    }
private:
    int min(int x, int y) {
        return x > y ? y : x;
    }
};