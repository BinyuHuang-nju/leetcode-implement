#include <iostream>
using namespace std;
#include <vector>
#include <map>
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); i++)
            mp[groupSizes[i]].push_back(i);
        vector<vector<int>> result;
        for (map<int, vector<int>>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
            for (auto cur = iter->second.begin(); cur != iter->second.end(); cur += iter->first)
                result.push_back(vector<int>(cur, cur + iter->first));
        }
        return result;
    }
};
int main() {
    vector<int> a = { 3,3,3,3,3,1,3 };
    Solution sol;
    sol.groupThePeople(a);
    return 0;
}