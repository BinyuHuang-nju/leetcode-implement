#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <bitset>
class Solution1 {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        if (n == 1)
            return { 0 };
        map<string, int> mp;
        vector<bitset<2200>> companies(n);
        int cur_no = 0;
        for (int i = 0; i < n; i++) {
            for (string word : favoriteCompanies[i]) {
                if (!mp.count(word))
                    mp[word] = cur_no++;
                companies[i][mp[word]] = 1;
            }
        }
        vector<int> results;
        vector<bool> failed(n, false);
        for (int i = 0; i < n; i++) {
            if (failed[i])
                continue;
            for (int j = 0; j < n; j++) {
                if (j == i || failed[j])
                    continue;
                bool fail_i = false, fail_j = false;
                for (int k = 0; k < cur_no; k++) {
                    if (!companies[i][k] && companies[j][k])
                        fail_i = true;
                    else if (companies[i][k] && !companies[j][k])
                        fail_j = true;
                }
                if (fail_i != fail_j) {
                    if (fail_i) {
                        failed[i] = true;
                        break;
                    }
                    else {
                        failed[j] = true;
                    }
                }
            }
            if (!failed[i])
                results.push_back(i);
        }
        return results;
    }
};
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        int n = favoriteCompanies.size();
        if (n == 1)
            return { 0 };
        map<string, int> mp;
        int cur_no = 0;
        for (int i = 0; i < n; i++) {
            for (string word : favoriteCompanies[i]) {
                if (!mp.count(word))
                    mp[word] = cur_no++;
            }
        }
        vector<vector<bool>> companies(n, vector<bool>(cur_no,false));
        for (int i = 0; i < n; i++) {
            for (string word : favoriteCompanies[i]) {
                companies[i][mp[word]] = true;
            }
        }
        vector<int> results;
        vector<bool> failed(n, false);
        for (int i = 0; i < n; i++) {
            if (failed[i])
                continue;
            for (int j = 0; j < n; j++) {
                if (j == i || failed[j])
                    continue;
                bool fail_i = false, fail_j = false;
                for (int k = 0; k < cur_no; k++) {
                    if (!companies[i][k] && companies[j][k])
                        fail_i = true;
                    else if (companies[i][k] && !companies[j][k])
                        fail_j = true;
                }
                if (fail_i != fail_j) {
                    if (fail_i) {
                        failed[i] = true;
                        break;
                    }
                    else {
                        failed[j] = true;
                    }
                }
            }
            if (!failed[i])
                results.push_back(i);
        }
        return results;
    }
};
int main() {
    Solution sol;
    vector<vector<string>> a = { {"leetcode","google","facebook"},{"google","microsoft"},{"google","facebook"},\
    {"google"}, {"amazon"} };
    sol.peopleIndexes(a);
    return 0;
}