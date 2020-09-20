#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Solution {
public:
    int maxLength(vector<string>& arr) {
        return traceback(arr, 0, 0);
    }
    int traceback(vector<string>& arr, int start, int mp) {
        if (start == arr.size())
            return 0;
        int tag = mp;
        for (char ch : arr[start]) {
            if (mp & 1 << (ch - 'a'))
                return traceback(arr, start + 1, tag);
            mp = mp | (1 << (ch - 'a'));
        }
        return max(traceback(arr, start + 1, mp) + (int)arr[start].length(), traceback(arr, start + 1, tag));
    }
};
int main() {
    Solution sol;
    vector<string> arr = { "cha","r","act","ers" };
    int x = sol.maxLength(arr);
    return 0;
}