#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>

class Solution1 {

public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        if (A.size() < 2)
            return A;
        sort(A.begin(), A.end());
        vector<bool> used(A.size(), false);
        vector<int> results;
        for (int i = 0; i < B.size(); i++) {
            bool existBigger = false;
            for (int j = 0; j < A.size(); j++) {
                if (A[j] > B[i] && !used[j]) {
                    used[j] = true;
                    results.push_back(A[j]);
                    existBigger = true;
                    break;
                }
            }
            if (!existBigger) {
                results.push_back(-1);
            }
        }
        queue<int> que;
        for (int i = 0; i < A.size(); i++) {
            if (!used[i])
                que.push(A[i]);
        }
        for (int i = 0; i < results.size(); i++) {
            if (results[i] == -1) {
                results[i] = que.front();
                que.pop();
            }
        }
        return results;
    }
};

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        multiset<int> ms(A.begin(), A.end());

        vector<int> res(A.size(), -1);
        for (int i = 0; i < B.size(); i++) {
            auto iter = ms.upper_bound(B[i]);
            if (iter != ms.end()) {
                res[i] = *iter;
                ms.erase(iter);
            }
        }

        auto iter = ms.begin();
        for (auto& num : res) {
            if (num == -1) num = *iter++;
        }
        return res;
    }
};

int main() {
    vector<int> a = { 15448,14234,13574,19893,6475 };
    vector<int> b = { 14234,6475,19893,15448,13574 };
    Solution sol;
    sol.advantageCount(a, b);
    return 0;
}