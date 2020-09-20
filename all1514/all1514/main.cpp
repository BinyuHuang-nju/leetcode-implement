#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> nodes(n);
        for (int i = 0; i < edges.size(); i++) {
            nodes[edges[i][0]].push_back(make_pair( succProb[i], edges[i][1]));
            nodes[edges[i][1]].push_back(make_pair( succProb[i], edges[i][0]));
        }
        vector<double> prob(n, 0.0);
        priority_queue<pair<double, int>> queNode;
        queNode.push(make_pair(1.0, start));
        prob[start] = 1.0;
        pair<double, int> v;
        while (!queNode.empty()) {
            v = queNode.top();
            queNode.pop();
            if (v.first < prob[v.second])
                continue;
            for (pair<double, int> w : nodes[v.second]) {
                if (v.first * w.first < 1e-5)
                    continue;
                if (v.first * w.first > prob[w.second]) {
                    prob[w.second] = v.first * w.first;
                    queNode.push(make_pair(prob[w.second], w.second));
                }
            }
        }
        return prob[end];
    }
};
int main() {
    Solution sol;
    vector<vector<int>> edges = { {0,1},{1,2},{0,2} };
    vector<double> succ = { 0.5,0.5,0.2 };
    sol.maxProbability(3, edges, succ, 0, 2);
    return 0;
}