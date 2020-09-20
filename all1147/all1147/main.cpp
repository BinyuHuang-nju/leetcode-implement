#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <string>
class Solution {
public:
    int longestDecomposition(string text) {
        for (int i = 1; i <= text.length() / 2; i++) {
            if (text.substr(0, i) == text.substr(text.length() - i, i)) {
                if (i * 2 < text.length())
                    return 2 + longestDecomposition(text.substr(i, text.length() - 2 * i));
                else if (i * 2 == text.length())
                    return 2;
            }
        }
        return 1;
    }
};
int main() {
    Solution sol;
    //int reuslt = sol.longestDecomposition("ghiabcdefhelloadamhelloabcdefghi");
    //int reuslt = sol.longestDecomposition("merchant");
    int reuslt = sol.longestDecomposition("antaprezatepzapreanta");
    return 0;
}