#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        int i, time = 0;
        for (i = 0; i < tasks.size(); i++)
            count[tasks[i] - 'A']++;
        sort(count.begin(), count.end());
        while (count[25] > 0) {
            for (i = 0; i <= n; i++) {
                if (count[25] == 0)
                    break;
                if (i < 26 && count[25 - i]>0)
                    count[25 - i]--;
                time++;
            }
            sort(count.begin(), count.end());
        }
        return time;
    }
};