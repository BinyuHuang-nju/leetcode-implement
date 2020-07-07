#include <iostream>
using namespace std;
#include <string>
#include <cstring>

class Solution {
public:
    string longestPalindrome(string s) {

        string re = s.substr(0,1);
        int len = s.length(), i, j;
        int** store = new int* [len];
        for (i = 0; i < len; i++)
            store[i] = new int[len];
        int max = 1;
        for (i = 0; i < len; i++)
            store[i][i] = 1;
        for (i = 1; i < len; i++)
            store[i][i - 1] = 0;
        for(i=len-2;i>=0;i--)
            for (j = i + 1; j < len; j++) {
                if (s[i] == s[j]) {
                    if (store[i + 1][j - 1] == -1)
                        store[i][j] = -1;
                    else
                    {
                        store[i][j] = store[i + 1][j - 1] + 2;
                        if (store[i][j] > max) {
                            max = store[i][j];
                            //cout<<s << i<<" " <<j<<" "<<s.substr(i, j - i + 1)<<endl;
                            re = s.substr(i, j - i + 1);
                        }
                    }
                }
                else
                    store[i][j] = -1;
            }
        delete[]store;
        return re;
    }
};

int main() {
    string str, result;
    getline(cin, str);
    Solution sol;
    result = sol.longestPalindrome(str);
    cout << result;
    return 0;
}