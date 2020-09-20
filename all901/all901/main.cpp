#include <iostream>
using namespace std;
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

class StockSpanner {
private:
    struct Stock {
        int price;
        int nums;
    };
    stack<Stock> st;
public:
    StockSpanner() {

    }

    int next(int price) {
        Stock stock;
        stock.price = price;
        stock.nums = 1;
        if (st.empty() || price < st.top().price) {
            st.push(stock);
            return 1;
        }
        int res = 1;
        while (!st.empty() && st.top().price <= price) {
            res = res + st.top().nums;
            st.pop();
        }
        stock.nums = res;
        st.push(stock);
        return res;
    }
};