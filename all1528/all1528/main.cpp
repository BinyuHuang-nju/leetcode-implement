#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string result = s;
        for (int i = 0; i < indices.size(); i++) {
            if (indices[i] != i)
                result[indices[i]] = s[i];
        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 4,5,6,7,0,2,1,3 };
    sol.restoreString("codeleet", a);
    return 0;
}