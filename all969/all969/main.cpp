#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        if (A.size() < 2)
            return {};
        vector<int> sequences;
        for (int i = A.size() - 1; i > 0; i--) {
            int maxIndex = indexOfMax(A, 0, i);
            if (maxIndex == i)
                continue;
            if (maxIndex != 0) {
                reverseList(A, 0, maxIndex);
                sequences.push_back(maxIndex + 1);
            }
            reverseList(A, 0, i);
            sequences.push_back(i + 1);
        }
        return sequences;
    }
    int indexOfMax(vector<int>& A, int start, int end) {
        int index = start;
        for (int i = start + 1; i <= end; i++)
            if (A[i] > A[index])
                index = i;
        return index;
    }
    void reverseList(vector<int>& A, int start, int end) {
        int temp;
        for (int i = start, j = end; i < j; i++, j--) {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }
};