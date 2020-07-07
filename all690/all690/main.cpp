#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
private:
    struct Employ {
        int importance;
        vector<int> subordinates;
    };
public:
    int getImportance(vector<Employee*> employees, int id) {
        map<int, Employ> employ;
        int i;
        Employ temp;
        for (i = 0; i < employees.size(); i++) {
            temp.importance = employees[i]->importance;
            temp.subordinates = employees[i]->subordinates;
            employ[employees[i]->id] = temp;
        }
        int res = 0, p;
        queue<int> que;
        que.push(id);
        while (!que.empty()) {
            p = que.front();
            que.pop();
            res = res + employ[p].importance;
            for (i = 0; i < employ[p].subordinates.size(); i++)
                que.push(employ[p].subordinates[i]);
        }
        return res;
    }
};