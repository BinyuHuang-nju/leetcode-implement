#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <stack>

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        map<int, int> hashmap;
        for (int i = 0; i < nums2.size(); i++) {
            if (st.empty())
                st.push(nums2[i]);
            else {
                while (!st.empty() && st.top() < nums2[i]) {
                    hashmap[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        vector<int> res;
        for (int i = 0; i < nums1.size(); i++) {
            if (hashmap.count(nums1[i]) != 0)
                res.push_back(hashmap[nums1[i]]);
            else
                res.push_back(-1);
        }
        return res;
    }
};
int main() {
    vector<int> a = { 4,1,2 }, b = { 1,3,4,2 };
    Solution sol;
    vector<int> c = sol.nextGreaterElement(a, b);
    return 0;
}