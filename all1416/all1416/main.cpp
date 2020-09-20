#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution1 {   // true but exceeds time limitations 27/83
private:
    const long long M = 1e9 + 7;
public:
    int numberOfArrays(string s, int k) {
        long long result = 0;
        backtrace(result, s, 0, s.length(), k);
        return result;
    }
    void backtrace(long long& result, string s, int start, int n, int k) {
        if (start == n) {
            result = (result + 1) % M;
            return;
        }
        if (s[start] == '0')
            return;
        long long cur = 0L;
        for (int i = start; i < n; i++) {
            cur = cur * 10 + (s[i] - '0');
            if (cur > (long long)k)
                break;
            backtrace(result, s, i + 1, n, k);
        }
    }
};
class Solution2 {    // true but exceeds time limitations  75/83
private:
    const long long M = 1e9 + 7;
    vector<long long> memo;
public:
    int numberOfArrays(string s, int k) {
        memo = vector<long long>(s.length(), -1);
        backtrace(s, 0, s.length(), k);
        return (int)memo[0];
    }
    long long backtrace(string s, int start, int n, int k) {
        if (start == n)
            return 1;
        if (s[start] == '0')
            return memo[start]=0;
        if (memo[start] != -1)
            return memo[start];
        long long cur = 0L, result = 0L;
        for (int i = start; i < n; i++) {
            cur = cur * 10 + (long long)(s[i] - '0');
            if (cur > (long long)k)
                break;
            result = (result + backtrace(s, i + 1, n, k)) % M;
        }
        return memo[start] = result;
    }
};
class Solution {
private:
    const long long M = 1e9 + 7;
public:
    int numberOfArrays(string s, int k) {
        int n = s.length();
        vector<long long> memo(n+1, 0);
        memo[n] = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0')
                continue;
            long long cur = 0L, result = 0L;
            for (int j = i; j < n; j++) {
                cur = cur * 10 + (long long)(s[j] - '0');
                if (cur > (long long)k)
                    break;
                result = (result + memo[j + 1]) % M;
            }
            memo[i] = result;
        }
        return (int)memo[0];
    }
};
int main() {
    Solution sol;
    sol.numberOfArrays("1234567890", 90);
    return 0;
}