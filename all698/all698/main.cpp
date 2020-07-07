#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Solution {
private:
    int average = 0;
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1)
            return true;
        int max = 0, sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum = sum + nums[i];
            if (max < nums[i])
                max = nums[i];
        }
        if (sum % k != 0)
            return false;
        average = sum / k;
        if (average < max)
            return false;
        map <int, int>hashMap;
        for (int i = 0; i < nums.size(); i++)
            hashMap[nums[i]] += 1;
        return dfs(hashMap, k, 0);
    }
    bool dfs(map<int, int>& hashMap, int curK, int curAvg) {
        if (curAvg == 0) {
            if (curK == 0)
                return true;
            else
                return dfs(hashMap, curK - 1, average);
        }
        if (curAvg < 0)
            return false;
        for (int num = curAvg; num > 0; num--) {
            if (hashMap.count(num) && hashMap[num] > 0) {
                hashMap[num] -= 1;
                if (dfs(hashMap, curK, curAvg - num))
                    return true;
                hashMap[num] += 1;
            }
        }
        return false;
    }
};