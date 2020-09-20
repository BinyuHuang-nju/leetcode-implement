#include <iostream>
using namespace std;
#include <vector>
#include <map>

class Solution1 { // true but exceeds time limitation.
private:
    int max;
public:
    int lenLongestFibSubseq(vector<int>& A) {
        max = 0;
        vector<int> fib;
        search(A, 0, fib);
        return max > 2 ? max : 0;
    }
private:
    void search(vector<int>& A, int start, vector<int>& fib) {
        if (fib.size() > max)
            max = fib.size();
        if (start >= A.size())
            return;
        if (fib.size() < 2) {
            for (int i = start; i < A.size(); i++) {
                fib.push_back(A[i]);
                search(A, i + 1, fib);
                fib.pop_back();
            }
        }
        else {
            int num = fib[fib.size() - 2] + fib[fib.size() - 1];
            for (int i = start; i < A.size(); i++) {
                if (A[i] > num)
                    break;
                else if (A[i] == num) {
                    fib.push_back(A[i]);
                    search(A, i + 1, fib);
                    fib.pop_back();
                    break;
                }
            }
        }
    }
};


class Solution {  // true but exceeds time limitation.

public:
    int lenLongestFibSubseq(vector<int>& A) {
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
        map<int, int> table;
        for (int i = 0; i < A.size(); i++)
            table[A[i]] = i;
        int max = 0;
        for (int i = 2; i < A.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (table.count(A[i] - A[j]) && table[A[i] - A[j]] < j) {
                    dp[j][i] = Max(dp[table[A[i] - A[j]]][j] + 1, 3);
                    if (dp[j][i] > max)
                        max = dp[j][i];
                }
            }
        }
        return max > 2 ? max : 0;
    }
private:
    int Max(int x, int y) {
        return x > y ? x : y;
    }
};
int main() {
    Solution sol;
    vector<int> a = { 1,2,3,4,5,6,7,8 };
    sol.lenLongestFibSubseq(a);
    return 0;
}