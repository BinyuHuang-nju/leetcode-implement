#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
class Solution1 {  //true but exceeds time limitations
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (vector<int> prerequisite : prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }
        vector<bool> results;
        vector<bool> visited(n, false);
        for (vector<int> query : queries) {
            int s = query[0], e = query[1];
            if (visited[s]) {
                bool find = false;
                for (int node : graph[s]) {
                    if (node == e) {
                        find = true;
                        break;
                    }
                }
                results.push_back(find);
                continue;
            }
            vector<int> reach;
            queue<int> queNode;
            int v;
            bool find = false;
            queNode.push(s);
            while (!queNode.empty()) {
                v = queNode.front();
                queNode.pop();
                reach.push_back(v);
                if (v == e)
                    find = true;
                if (visited[v]) {
                    for (int w : graph[v]) {
                        reach.push_back(w);
                        if (w == e)
                            find = true;
                    }
                }
                else {
                    for (int w : graph[v])
                        queNode.push(w);
                }
            }
            visited[s] = true;
            graph[s] = reach;
            results.push_back(find);
        }
        return results;
    }
};
class Solution2 { // improvement1: from top to bottom-> from bottom to top
public:             //true but exceeds time limitations
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> graph(n);
        for (vector<int> prerequisite : prerequisites) {
            graph[prerequisite[0]].push_back(prerequisite[1]);
        }
        vector<bool> results;
        vector<bool> visited(n, false);
        for (vector<int> query : queries) {
            int s = query[0], e = query[1];
            if (!visited[s])
                dfs(visited, graph, s);
            bool find = false;
            for (int node : graph[s]) {
                if (node == e) {
                    find = true;
                    break;
                }
            }
            results.push_back(find);
        }
        return results;
    }
    void dfs(vector<bool>& visited, vector<vector<int>>& graph, int v) {
        if (visited[v])
            return;
        vector<int> reach;
        reach.push_back(v);
        for (int w : graph[v]) {
            dfs(visited, graph, w);
            for (int u : graph[w])
                reach.push_back(u);
        }
        visited[v] = true;
        graph[v] = reach;
    }
};
class Solution3 { // improvement1: from top to bottom-> from bottom to top
public:                // improvement2: adjacency table-> adjacency matrix
                        // pass
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> graph(n, vector<bool>(n, false));
        for (vector<int> prerequisite : prerequisites) {
            graph[prerequisite[0]][prerequisite[1]] = true;
        }
        vector<bool> results;
        vector<bool> visited(n, false);
        for (vector<int> query : queries) {
            int s = query[0], e = query[1];
            if (!visited[s])
                dfs(visited, graph, s, n);
            results.push_back(graph[s][e]);
        }
        return results;
    }
    void dfs(vector<bool>& visited, vector<vector<bool>>& graph, int v, int n) {
        if (visited[v])
            return;
        int w;
        vector<bool> reach = graph[v];
        for (int i = 0; i < n; i++) {
            if (graph[v][i]) {
                dfs(visited, graph, i, n);
                for (int j = 0; j < n; j++) {
                    if (graph[i][j])
                        reach[j] = true;
                }
            }
        }
        visited[v] = true;
        graph[v] = reach;
    }
};
class Solution { // improvement1: from top to bottom-> from bottom to top
public:                // improvement2/3: adjacency table  + adjacency matrix
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<bool>> graph_matrix(n, vector<bool>(n, false));
        vector<vector<int>> graph_table(n);
        for (vector<int> prerequisite : prerequisites) {
            graph_matrix[prerequisite[0]][prerequisite[1]] = true;
            graph_table[prerequisite[0]].push_back(prerequisite[1]);
        }
        vector<bool> results;
        vector<bool> visited(n, false);
        for (vector<int> query : queries) {
            int s = query[0], e = query[1];
            dfs(visited, graph_matrix, graph_table, s, n);
            results.push_back(graph_matrix[s][e]);
        }
        return results;
    }
    void dfs(vector<bool>& visited, vector<vector<bool>>& graph_matrix, vector<vector<int>>& graph_table ,int v, int n) {
        if (visited[v])
            return;
        int w;
        vector<bool> reach_matrix = graph_matrix[v];
        vector<int> reach_table;
        for (int w : graph_table[v]) {
            dfs(visited, graph_matrix, graph_table, w, n);
            for (int u : graph_table[w])
                reach_matrix[u] = true;
        }
        visited[v] = true;
        graph_matrix[v] = reach_matrix;
        for (int i = 0; i < n; i++)
            if (reach_matrix[i])
                reach_table.push_back(i);
        graph_table[v] = reach_table;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {1,2},{1,0},{2,0} }, b = { {1,0},{1,2} };
    sol.checkIfPrerequisite(3,a,b);
    return 0;
}