#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
class Solution {
private:
    vector<int> parent;
    int Find(int x) {
        while (parent[x] >= 0)
            x = parent[x];
        return x;
    }
    void Union(int x1, int x2) {
        int root1 = Find(x1), root2 = Find(x2);
        if (root1 != root2) {
            if (parent[root1] > parent[root2])
                swap(root1, root2);
            parent[root1] = parent[root1] + parent[root2];
            parent[root2] = root1;
        }
    }
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        parent = vector<int>(s.length(), -1);
        for (vector<int> pr : pairs) {
            Union(pr[0], pr[1]);
        }
        map<int, vector<char>> mp;
        for (int i = 0; i < s.length(); i++) {
            int p = Find(i);
            if (!mp.count(p)) {
                vector<char> tmp;
                mp[p] = tmp;
            }
            mp[p].push_back(s[i]);
        }
        for (map<int, vector<char>>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
            sort(iter->second.begin(), iter->second.end(), [](char a, char b) {return a > b; });
        }
        for (int i = 0; i < s.length(); i++) {
            int p = Find(i);
            s[i] = mp[p].back();
            mp[p].pop_back();
        }
        return s;
    }
};
int main() {
    vector<vector<int>> a = { {0,3},{1,2} };
    Solution sol;
    sol.smallestStringWithSwaps("cxmtygkijtnsacggnqaxuzv", a);
    return 0;
}
