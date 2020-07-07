#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <string>

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int nums = rooms.size();
        queue<int> tobevisited;
        vector<bool> visited(nums, false);
        visited[0] = true;
        int havevisited = 1;
        tobevisited.push(0);
        int i, v, w;
        while (!tobevisited.empty()) {
            v = tobevisited.front();
            tobevisited.pop();
            for (i = 0; i < rooms[v].size(); i++) {
                w = rooms[v][i];
                if (!visited[w]) {
                    havevisited++;
                    visited[w] = true;
                    tobevisited.push(w);
                }
            }
        }
        if (havevisited == nums)
            return true;
        return false;
    }
};