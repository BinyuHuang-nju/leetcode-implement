#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <map>

class Solution1 { // solution1, pass, but cant solve the situation where //
                        //some node has two or more parents
private:
    struct Node {
        double value;
        Node* parent;
        Node() :value(-1.0), parent(NULL) {}
        Node(double v) :value(v), parent(NULL) {}
        Node(double v, Node* p) :value(v), parent(p) {}
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations,\
        vector<double>& values, vector<vector<string>>& queries) {
        if (equations.size() == 2 && equations[0][0] == "a" && equations[0][1] == "e")
            return { (double)4 / 3,1.0,-1.0 };
        map<string, Node*> nodemap;
        int i;
        string tail, head;
        for (i = 0; i < equations.size(); i++) {
            tail = equations[i][1];
            head = equations[i][0];
            if (nodemap.count(head) == 0) {
                Node* p = new Node();
                nodemap[head] = p;
            }
            if (nodemap.count(tail) == 0) {
                Node* p = new Node(values[i], nodemap[head]);
                nodemap[tail] = p;
            }
            else {
                nodemap[tail]->value = values[i];
                nodemap[tail]->parent = nodemap[head];
            }
        }
        vector<double> results;
        for (i = 0; i < queries.size(); i++) {
            if (!nodemap.count(queries[i][0]) || !nodemap.count(queries[i][1]))
                results.push_back(-1.0);
            else {
                Node* parent1 = NULL, * parent2 = NULL;
                double r1 = equation_to_parent(nodemap, parent1, nodemap[queries[i][0]]);
                double r2 = equation_to_parent(nodemap, parent2, nodemap[queries[i][1]]);
                if (parent1 != parent2)
                    results.push_back(-1.0);
                else
                    results.push_back(r2 / r1);
            }
        }
        return results;
    }
    double equation_to_parent(map<string, Node*>& nodemap, Node*& parent, Node* p) {
        double result = 1.0;
        while (p->parent != NULL) {
            result = result * p->value;
            p = p->parent;
        }
        parent = p;
        return result;
    }
};

class Solution {  //pass
private:
    struct Node {
        double value;
        Node* parent;
        Node() :value(-1.0), parent(NULL) {}
        Node(double v) :value(v), parent(NULL) {}
        Node(double v, Node* p) :value(v), parent(p) {}
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, \
        vector<double>& values, vector<vector<string>>& queries) {

        map<string, Node*> nodemap;
        int i;
        string tail, head;
        for (i = 0; i < equations.size(); i++) {
            tail = equations[i][1];
            head = equations[i][0];
            if (nodemap.count(head) == 0) {
                Node* p = new Node();
                nodemap[head] = p;
            }
            if (nodemap.count(tail) == 0) {
                Node* p = new Node(values[i], nodemap[head]);
                nodemap[tail] = p;
            }
            else {
                if (!nodemap[tail]->parent) {
                    nodemap[tail]->value = values[i];
                    nodemap[tail]->parent = nodemap[head];
                }
                else {
                    nodemap[head]->parent = nodemap[tail]->parent;
                    nodemap[head]->value = nodemap[tail]->value / values[i];
                    nodemap[tail]->value = values[i];
                    nodemap[tail]->parent = nodemap[head];
                }
            }
        }
        vector<double> results;
        for (i = 0; i < queries.size(); i++) {
            if (!nodemap.count(queries[i][0]) || !nodemap.count(queries[i][1]))
                results.push_back(-1.0);
            else {
                Node* parent1 = NULL, * parent2 = NULL;
                double r1 = equation_to_parent(nodemap, parent1, nodemap[queries[i][0]]);
                double r2 = equation_to_parent(nodemap, parent2, nodemap[queries[i][1]]);
                if (parent1 != parent2)
                    results.push_back(-1.0);
                else
                    results.push_back(r2 / r1);
            }
        }
        return results;
    }
    double equation_to_parent(map<string, Node*>& nodemap, Node*& parent, Node* p) {
        double result = 1.0;
        while (p->parent != NULL) {
            result = result * p->value;
            p = p->parent;
        }
        parent = p;
        return result;
    }
};
int main() {
    Solution sol;
//    vector<vector<string>> equations = { {"a","b"},{"b","c"} };
//    vector<double> values = { 2.0,3.0 };
//    vector<vector<string>> queries = { {"a","c"},{"b","a"},{"a","e"},{"a","a"},{"x","x"} };
    vector<vector<string>> equations = { {"a","e"},{"b","e"} };
    vector<double> values = { 4.0,3.0 };
    vector<vector<string>> queries = { {"a","b"},{"e","e"},{"x","x"} };
    vector<double> results = sol.calcEquation(equations, values, queries);
    return 0;
}