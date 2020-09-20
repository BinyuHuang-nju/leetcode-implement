#include <iostream>
using namespace std;
#include <vector>
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int space = 0;
        int last = -2;
        for (int i = 0; i <= flowerbed.size(); i++) {
            if (i == flowerbed.size() || flowerbed[i] == 1) {
                if (i == flowerbed.size()) {
                    space += (i - last - 1) / 2;
                }
                else if (last == -2) {
                    space += i / 2;
                }
                else {
                    space += (i - last - 2) / 2;
                }
                last = i;
            }
        }
        return space >= n;
    }
};