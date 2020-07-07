#include <iostream>
using namespace std;
#include <vector>
#include <map>
class Solution {
public:
    vector<int> partitionLabels(string S) {
        if (S.length() == 0)
            return { };
        if (S.length() == 1)
            return { 1 };
        map<char, int> lastIndex;
        int i;
        for (i = 0; i < S.length(); i++)
            lastIndex[S[i]] = i;
        vector<int> results;
        int start = 0, end = -1;
        while (end < (int)S.length() - 1) {
            start = end + 1;
            end = lastIndex[S[i]];
            i = start;
            while (i <= end) {
                if (lastIndex[S[i]] > end)
                    end = lastIndex[S[i]];
                i++;
            }
            results.push_back(end - start + 1);
        }
        return results;
    }
};
int main() {
    Solution sol;
    string a = "ababcbacadefegdehijhklij";
    sol.partitionLabels(a);
    return 0;
}