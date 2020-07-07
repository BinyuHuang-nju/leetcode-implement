#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h;
        for (int i = 0; i < citations.size(); i++) {
            h = citations.size() - i;
            if (h <= citations[i])
                return h;
        }
        return 0;
    }
};