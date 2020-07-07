#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> results;
        vector<bool> results_map(graph.size(), false);

        for (int i = 0; i < graph.size(); i++) {
            if (graph[i].size() == 0) {
                results.push_back(i);
                results_map[i] = true;
            }
        }
        while (1) {
            vector<int> temp;
            for (int i = 0; i < graph.size(); i++) {
                if (results_map[i] == true)
                    temp.push_back(i);
                else {
                    bool isSafe = true;
                    for (int j = 0; j < graph[i].size(); j++) {
                        if (!results_map[graph[i][j]])
                            isSafe = false;
                    }
                    if (isSafe) {
                        temp.push_back(i);
                        results_map[i] = true;
                    }
                }
            }
            if (temp.size() == results.size())
                break;
            else {
                results.swap(temp);
            }
        }
        return results;
    }
};