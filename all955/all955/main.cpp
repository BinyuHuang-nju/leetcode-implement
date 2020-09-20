#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        if (A.size() < 2)
            return 0;
        vector<int> temp;
        for (int i = 0; i < A.size() - 1; i++)
            temp.push_back(i);
        int result = 0;
        for (int i = 0; i < A[0].size() && temp.size(); i++) {
            bool flag = false;
            for (int t : temp) {
                if (A[t][i] > A[t + 1][i]) {
                    flag = true;
                    result++;
                    break;
                }
            }
            if (!flag) {
                vector<int> temp2;
                for (int t : temp)
                    if (A[t][i] == A[t + 1][i])
                        temp2.push_back(t);
                temp = temp2;
            }
        }
        return result;
    }
};