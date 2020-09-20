#include <iostream>
using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int depth = -1;
        vector<int> results;
        for (char ch : seq) {
            if (ch == '(') {
                depth++;
                results.push_back(depth % 2);
            }
            else {
                results.push_back(depth % 2);
                depth--;
            }
        }
        return results;
    }
};