#include <iostream>
using namespace std;
#include <vector>
#include <queue>

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        if (prerequisites.size() == 0) {
            for(int i=0;i<numCourses;i++)
                res.push_back(i);
            return res;
        }
       /* if (prerequisites.size() == 1) {
            res.push_back(prerequisites[0][1]);
            res.push_back(prerequisites[0][0]);
            return res;
        }*/
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
                res.push_back(i);
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
                    res.push_back(w);
                    visited++;
                }
            }
        }
        if (visited == numCourses) {
            return res;
        }
        vector<int> tmp;
        return tmp;
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
int main() {
    vector<vector<int>> a = { {1,0} };
    Solution sol;
    vector<int> res = sol.findOrder(2, a);
    return 0;
}