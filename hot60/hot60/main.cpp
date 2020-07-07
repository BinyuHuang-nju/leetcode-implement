#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if (prerequisites.size() <= 1)
            return true;
        Node* node = new Node[numCourses]();
        int i;
        for (i = 0; i < prerequisites.size(); i++) {
            node[prerequisites[i][1]].outdegree++;
            node[prerequisites[i][1]].nodes.push_back(prerequisites[i][0]);
            node[prerequisites[i][0]].indegree++;
        }
        queue<int> q;
        int visited = 0, v, w;
        for (i = 0; i < numCourses; i++)
            if (node[i].indegree == 0) {
                q.push(i);
                visited++;
            }
        while (!q.empty()) {
            v = q.front();
            q.pop();
            for (i = 0; i < node[v].outdegree; i++) {
                w = node[v].nodes[i];
                node[w].indegree--;
                if (node[w].indegree == 0) {
                    q.push(w);
                    visited++;
                }
            }
        }
        if (visited == numCourses)
            return true;
        return false;
    }
private:
    struct Node {
        //int val;
        int indegree;
        int outdegree;
        vector<int> nodes;
        Node() :indegree(0), outdegree(0) {}
    };
};