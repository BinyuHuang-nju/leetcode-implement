#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        int len = strs.size();
        vector<double> flag;
        double cur;
        int i, j;
        for (i = 0; i < len; i++) {
            cur = 1.0;
            for (j = 0; j < strs[i].length(); j++)
                cur = cur * index[strs[i][j] - 'a'];
            flag.push_back(cur);
        }
        
        map<double, vector<string>> hashtable;
        for (i = 0; i < len; i++)
            hashtable[flag[i]].push_back(strs[i]);
              //hashtable.insert(pair<double, vector<string>>(flag[i],strs[i]));
        for (auto iter = hashtable.begin(); iter != hashtable.end(); iter++)
            res.push_back(iter->second);
        return res;
    }
private:
    double index[26] = { 2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101 };
};
int main() {
    vector<string> strs = { "eat","tea", "tan", "ate", "nat", "bat" };
    Solution sol;
    vector<vector<string>> res=sol.groupAnagrams(strs);
    return 0;
}

class Solu {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        for (int i = 0; i < strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(), key.end());
            if (m.find(key) == m.end()) m[key] = { strs[i] };
            else m[key].push_back(strs[i]);
        }
        vector<vector<string>> ret;
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            ret.push_back(iter->second);
        }
        return ret;
    }
};
