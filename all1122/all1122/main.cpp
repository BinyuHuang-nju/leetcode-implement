#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> results, out_arr2;
        map<int, int> mp1, mp2;
        for (int a : arr2)
            mp2[a] = 1;
        for (int a : arr1) {
            if (mp2.count(a)) {
                if (!mp1.count(a))
                    mp1[a] = 1;
                else
                    mp1[a]++;
            }
            else
                out_arr2.push_back(a);
        }
        sort(out_arr2.begin(), out_arr2.end());
        for (int a : arr2) {
            for (int i = 0; i < mp1[a]; i++)
                results.push_back(a);
        }
        for (int a : out_arr2)
            results.push_back(a);
        return results;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 2,3,1,3,2,4,6,7,9,2,19 }, b = { 2,1,4,3,9,6 };
    sol.relativeSortArray(a, b);
    return 0;
}