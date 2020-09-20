#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> pq;
        if(a>0)
            pq.push(make_pair(a, 0));
        if(b>0)
            pq.push(make_pair(b, 1));
        if(c>0) 
            pq.push(make_pair(c, 2));
        string result = "";
        pair<int, int> tmp;
        int continuity = 0;
        while (!pq.empty()) {
            tmp = pq.top();
            pq.pop();
            if (result.empty() || result.back() != 'a' + tmp.second) {
                result += ('a' + tmp.second);
                tmp.first--;
                if (tmp.first > 0)
                    pq.push(tmp);
                continuity = 1;
            }
            else if (continuity < 2) {
                result += ('a' + tmp.second);
                tmp.first--;
                if (tmp.first > 0)
                    pq.push(tmp);
                continuity++;
            }
            else {
                if (pq.empty())
                    break;
                else {
                    pair<int, int> tmp2 = pq.top();
                    pq.pop();
                    pq.push(tmp);
                    result += ('a' + tmp2.second);
                    tmp2.first--;
                    if (tmp2.first > 0)
                        pq.push(tmp2);
                    continuity = 1;
                }
            }
        }
        return result;
    }
};
int main() {
    Solution sol;
    sol.longestDiverseString(2,2,1);
    return 0;
}