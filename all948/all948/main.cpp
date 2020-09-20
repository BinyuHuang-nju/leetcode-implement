#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        if (tokens.size() == 0)
            return 0;
        if (tokens.size() == 1)
            return P < tokens[0] ? 0 : 1;
        sort(tokens.begin(), tokens.end());
        int point = 0, max = 0;
        int i = 0, j = tokens.size() - 1;
        while (i <= j) {
            if (P >= tokens[i]) {
                point++;
                if (point > max)
                    max = point;
                P = P - tokens[i];
                i++;
            }
            else {
                P = P + tokens[j];
                point--;
                j--;
            }
        }
        return max;
    }
};