#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int numsof5 = 0, numsof10 = 0;
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                numsof5++;
            }
            else if (bills[i] == 10) {
                if (numsof5 > 0) {
                    numsof5--;
                    numsof10++;
                }
                else
                    return false;
            }
            else {    //bills[i] == 20
                if (numsof10 > 0 && numsof5 > 0) {
                    numsof10--;
                    numsof5--;
                }
                else if (numsof5 > 2) {
                    numsof5 = numsof5 - 3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};