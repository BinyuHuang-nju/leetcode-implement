#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string result = "";
        char a = 'a', b = 'b';
        if (A < B) {
            swap(A, B);
            swap(a, b);
        }
        while (A > 0 || B > 0) {
            if (A > 0) {
                result += a;
                A--;
            }
            if (A > B) {
                result += a;
                A--;
            }
            if (B > 0) {
                result += b;
                B--;
            }
        }
        return result;
    }
};