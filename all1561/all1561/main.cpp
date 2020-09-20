#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int len = piles.size(), n = len / 3;
        int count = 0, result = 0;
        sort(piles.begin(), piles.end());
        for (int i = len - 2; i >= 0 && count < n; i = i - 2) {
            result += piles[i];
            count++;
        }
        return result;
    }
};