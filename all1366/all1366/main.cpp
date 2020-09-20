#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    string rankTeams(vector<string>& votes) {
        int votesNum = votes.size(), teamNum = votes[0].length();
        if (votesNum == 1 || teamNum==1)
            return votes[0];
        vector<vector<int>> rank(26, vector<int>(teamNum + 1, 0));
        for (int i = 0; i < 26; i++)
            rank[i][teamNum] = 25 - i;
        for (string vote : votes) {
            for (int i = 0; i < teamNum; i++) {
                rank[vote[i] - 'A'][i]++;
            }
        }
        sort(rank.begin(), rank.end(), greater<vector<int>>());
        string result = "";
        for (int i = 0; i < teamNum; i++) {
            result += (char)'A' + 25 - rank[i][teamNum];
        }
        return result;
    }
};