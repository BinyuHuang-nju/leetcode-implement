#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool canWinNim(int n) {
        if (n <= 3)
            return true;
        return (n % 4) ? true : false;
    }
};