#include <iostream>
using namespace std;
#include <vector>

class Solution1  //190/120
{
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        int i = 0, j;
        vector<int> choose;
        while (i < prices.size() - 1) {
            j = i;
            while (j < prices.size() - 1 && prices[j + 1] >= prices[j])
                j++;
            if (i < j) {
                choose.push_back(prices[j] - prices[i]);
            }
            i = j + 1;
        }
        if (choose.size() == 0)
            return 0;
        if (choose.size() == 1)
            return choose[0];
        if (choose.size() == 2)
            return choose[0] + choose[1];
        int max = 0;
        for (i = 0; i < 2; i++) {
            max = i;
            for (j = i + 1; j < choose.size(); j++) {
                if (choose[j] > choose[max])
                    max = j;
            }
            if (max != i) {
                int temp = choose[i];
                choose[i] = choose[max];
                choose[max] = temp;
            }
        }
        return choose[0] + choose[1];
    }
};

class Solution1 //pass
{
private:
    int max(int x, int y) {
        return x > y ? x : y;
    }
    int min(int x, int y) {
        return x < y ? x : y;
    }
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<int> dp1(prices.size(), 0);
        vector<int> dp2(prices.size(), 0);
        int minval = prices[0], maxval = prices[prices.size() - 1];
        for (int i = 1; i < prices.size(); i++) {
            dp1[i] = max(dp1[i - 1], prices[i] - minval);
            minval = min(minval, prices[i]);
        }
        for (int i = prices.size() - 2; i >= 0; i--) {
            dp2[i] = max(dp2[i + 1], maxval - prices[i]);
            maxval = max(maxval, prices[i]);
        }
        int max = dp1[0] + dp2[0];
        for (int i = 1; i < prices.size(); i++)
            if (max < dp1[i] + dp2[i])
                max = dp1[i] + dp2[i];
        return max;
    }
};

class Solution { //pass
private:
    int max(int x, int y) {
        return x > y ? x : y;
    }
    int max(int x, int y, int z) {
        int m = x > y ? x : y;
        return m > z ? m : z;
    }
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2)
            return 0;
        vector<vector<vector<int>>> dp\
            (prices.size(), vector<vector<int>>(3, vector<int>(2, 0)));
        int i, j, k;
        for (i = 0; i < 3; i++) {
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for (i = 1; i < prices.size(); i++) {
            for (j = 0; j < 3; j++) {
                if (j == 0)
                    dp[i][j][0] = dp[i - 1][j][0];
                else
                    dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j - 1][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j][0] - prices[i]);
            }
        }
        return max(dp[prices.size() - 1][0][0], dp[prices.size() - 1][1][0], dp[prices.size() - 1][2][0]);
    }
};

int main() {
    vector<int> a = { 1,2,4,2,5,7,2,4,9,0 };
    Solution sol;
    cout << sol.maxProfit(a);
    return 0;
}