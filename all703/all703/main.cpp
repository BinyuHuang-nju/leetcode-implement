#include <iostream>
using namespace std;
#include <vector>

class KthLargest {
private:
    int* heap;
    int size;
    int currentSize;
private:
    void siftDown(int start, int m) {
        int i = start, j = 2 * i + 1;
        int temp = heap[i];
        while (j <= m) {
            if (j<m && heap[j]>heap[j + 1])
                j++;
            if (temp <= heap[j])
                break;
            else {
                heap[i] = heap[j];
                i = j;
                j = j * 2 + 1;
            }
        }
        heap[i] = temp;
    }
    void siftUp(int start) {
        int j = start, i = (j - 1) / 2;
        int temp = heap[j];
        while (j > 0) {
            if (heap[i] <= temp)
                break;
            else {
                heap[j] = heap[i];
                j = i;
                i = (i - 1) / 2;
            }
        }
        heap[j] = temp;
    }
public:
    KthLargest(int k, vector<int>& nums) {
        heap = new int[k];
        size = k;
        currentSize = 0;
        for (int num : nums)
            add(num);
    }

    int add(int val) {
        if (currentSize < size) {
            heap[currentSize] = val;
            siftUp(currentSize);
            currentSize++;
        }
        else {
            if (heap[0] < val) {
                heap[0] = val;
                siftDown(0, size - 1);
            }
        }
        return heap[0];
    }
    ~KthLargest() {
        delete[]heap;
    }
};