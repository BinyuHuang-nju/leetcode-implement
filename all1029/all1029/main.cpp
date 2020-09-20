#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
private:
    struct Trip {
        int index;
        int costdiff;
    };

public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<Trip> infos(costs.size());
        Trip temp;
        for (int i = 0; i < costs.size(); i++) {
            temp.index = i;
            temp.costdiff = costs[i][0] - costs[i][1];
            infos[i] = temp;
        }
        sort(infos.begin(), infos.end(), [](Trip a, Trip b) {return a.costdiff < b.costdiff; });
        int result = 0;
        for (int i = 0; i < costs.size() / 2; i++)
            result += costs[infos[i].index][0];
        for (int i = costs.size() / 2; i < costs.size(); i++)
            result += costs[infos[i].index][1];
        return result;
    }
};