#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int len = arr.size();
        if (len < 2)
            return len;
        int result = 1;
        vector<int> list(len, 1);
        for (int i = 1; i < len; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[i] - arr[j] == difference)
                    list[i] = max(list[i], list[j] + 1);
            }
            result = max(result, list[i]);
        }
        return result;
    }
};

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int len = arr.size();
        if (len < 2)
            return len;
        int result = 1;
        map<int, int> mp;
        vector<int> list(len, 1);
        for (int i = 0; i < len; i++) {
            if (mp.count(arr[i] - difference)) {
                list[i] = max(list[i], list[mp[arr[i] - difference]] + 1);
            }
            if (!mp.count(arr[i]))
                mp[arr[i]] = i;
            else {
                if (list[mp[arr[i]]] < list[i])
                    mp[arr[i]] = i;
            }
            result = max(result, list[i]);
        }
        return result;
    }
}; 

int main() {
    Solution sol;
    vector<int> a = { 1,5,7,8,5,3,4,2,1 };
    sol.longestSubsequence(a, -2);
    return 0;
}
int longestArithSeqLength(vector<int>& A) {
    int len = A.size();
    if (len < 3)
        return len;
    int result = 2;
    vector<map<int, int>> list(len);
    for (int i = 1; i < len; i++) {
        for (int j = 0; j < i; j++) {
            if (!list[j].count(A[i] - A[j]))
                list[i][A[i] - A[j]] = 2;
            else {
                list[i][A[i] - A[j]] = list[j][A[i] - A[j]] + 1;
                result = max(result, list[i][A[i] - A[j]]);
            }
        }
    }
    return result;
}