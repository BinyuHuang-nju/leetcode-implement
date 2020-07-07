#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> results;
        for (string op : ops) {
            int size = results.size();
            if (op == "+") {
                if (size >= 2) {
                    results.push_back(results[size - 2] + results[size - 1]);
                }
            }
            else if (op == "D") {
                if (size >= 1)
                    results.push_back(results[size - 1] * 2);
            }
            else if (op == "C") {
                if (size >= 1)
                    results.pop_back();
            }
            else {
                results.push_back(stoi(op));
            }
        }
        int result = 0;
        for (int re : results)
            result += re;
        return result;
    }
};