#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>> remains;
        for (vector<int> restaurant : restaurants) {
            if (veganFriendly <= restaurant[2] && maxPrice >= restaurant[3] && maxDistance >= restaurant[4])
                remains.push_back({ restaurant[0], restaurant[1] });
        }
        sort(remains.begin(), remains.end(), [](vector<int>& a, vector<int>& b) {
            if (a[1] != b[1]) return a[1] > b[1];
            return a[0] > b[0]; });
        vector<int> results;
        for (vector<int> remain : remains)
            results.push_back(remain[0]);
        return results;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {1,4,1,40,10},{2,8,0,50,5},{3,8,1,30,4},{4,10,0,10,3},{5,1,1,15,1} };
    vector<int> re= sol.filterRestaurants(a, 0, 50, 10);
    return 0;
}