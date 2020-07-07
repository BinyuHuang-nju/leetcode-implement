#include <iostream>
using namespace std;
#include <vector>
class Solution1 { // exceeds time limitations
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> maxprofits(prices.size(), 0);
        for (int i = 1; i < prices.size(); i++) {
            maxprofits[i] = maxprofits[i - 1];
            for (int j = 0; j < i; j++) {
                if (prices[i] > prices[j] + fee)
                    maxprofits[i] = max(maxprofits[i], maxprofits[j] + prices[i] - prices[j] - fee);
            }
        }
        return maxprofits[prices.size() - 1];
    }
private:
    int max(int x, int y) {
        return x > y ? x : y;
    }
};


class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> profits_buying(prices.size(), 0);
        vector<int> profits_selled(prices.size(), 0);
        profits_buying[0] = -prices[0];
        for (int i = 1; i < prices.size(); i++) {
            profits_buying[i] = max(profits_buying[i - 1], profits_selled[i - 1] - prices[i]);
            profits_selled[i] = max(profits_selled[i - 1], profits_buying[i - 1] + prices[i] - fee);
        }
        return profits_selled[prices.size() - 1];
    }
private:
    int max(int x, int y) {
        return x > y ? x : y;
    }
};