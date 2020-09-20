#include <iostream>
using namespace std;
#include <vector>
#include <string>
class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> results;
        int index = 0;
        for (int i = 1; i <= n; i++) {
            if (target[index] == i) {
                results.push_back("Push");
                index++;
                if (index == target.size())
                    break;
            }
            else {
                results.push_back("Push");
                results.push_back("Pop");
            }
        }
        return results;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,3 };
    sol.buildArray(a, 4);
    return 0;
}