#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution1 { // true but exceeds time limitations
public:
    string decodeAtIndex(string S, int K) {
        string result;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] >= '0' && S[i] <= '9') {
                int d = S[i] - '1';
                string temp = result;
                for (int j = 0; j <= d - 1; j++)
                    result = result + temp;
            }
            else
                result = result + S.substr(i, 1);
            if (K <= result.length())
                return result.substr(K - 1, 1);
        }
        return "";
    }
};

class Solution {
public:
    string decodeAtIndex(string S, int K) {
        long long int total_length = 0;
        int i;
        for (i = 0; i < S.length(); i++) {
            if (S[i] >= '0' && S[i] <= '9')
                total_length *= (S[i] - '0');
            else
                total_length++;
            if (total_length >= K)
                break;
        }
        if (total_length < K)
            return "";
        long long int cur = total_length;
        for (; i >= 0; i--) {
            K = K % cur;
            if (S[i] >= '0' && S[i] <= '9') {
                cur /= (S[i] - '0');
            }
            else {
                if (K == 0)
                    return S.substr(i, 1);
                cur--;
            }
        }
        return "";
    }
};

int main() {
    Solution sol;
    sol.decodeAtIndex("leet2code3", 10);
    return 0;
}