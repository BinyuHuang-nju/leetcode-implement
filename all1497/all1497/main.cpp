#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        for (int& element : arr) {
            element = element % k;
            if (element < 0)
                element += k;
        }
        vector<int> count(k, 0);
        for (int element : arr) {
            count[element]++;
        }
        if (count[0] % 2 != 0)
            return false;
        for (int i = 1, j = k - 1; i <= j; i++, j--) {
            if (i != j) {
                if (count[i] != count[j])
                    return false;
            }
            else {
                if (count[i] % 2 != 0)
                    return false;
            }
        }
        return true;
    }
};
int main() {
    vector<int> a = { -1,-1,-1,-1,2,2,-2,-2 };
    Solution sol;
    sol.canArrange(a,3);
    return 0;
}