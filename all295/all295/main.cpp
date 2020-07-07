#include <iostream>
using namespace std;
#include <vector>

class MedianFinder_1 {
private:
    vector<int> arr;
public:
    /** initialize your data structure here. */
    MedianFinder_1() {

    }

    void addNum(int num) {
        int left = 0, right = arr.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (num == arr[mid])
                break;
            else if (num < arr[mid])
                right = mid - 1;
            else // num > arr[mid]
                left = mid + 1;
        }
        arr.push_back(num);
        if (num == arr[mid]) {
            for (int i = arr.size() - 1; i > mid; i--)
                arr[i] = arr[i - 1];
        }
        else {
            for (int i = arr.size() - 1; i > left; i--)
                arr[i] = arr[i - 1];
            arr[left] = num;
        }
    }

    double findMedian() {
        if (arr.size() % 2 != 0)
            return (double)arr[arr.size() / 2];
        else
            return ((double)arr[arr.size() / 2 - 1] + arr[arr.size() / 2]) / 2;
    }
};

class MinHeap {
private:
    vector<int> heap;
    int currentSize;
    void siftDown(int start, int m);
    void siftUp(int start);
public:
    MinHeap();
    void Insert(int x);
    void Remove(int& x);
    int CurrentSize() {
        return currentSize;
    }
    int min() {
        return heap[0];
    }
};
class MaxHeap {
private:
    vector<int> heap;
    int currentSize;
    void siftDown(int start, int m);
    void siftUp(int start);
public:
    MaxHeap();
    void Insert(int x);
    void Remove(int& x);
    int CurrentSize() {
        return currentSize;
    }
};
MinHeap::MinHeap() {
    currentSize = 0;
}
void MinHeap::siftDown(int start, int m) {
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
void MinHeap::siftUp(int start) {
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
void MinHeap::Insert(int x) {
    if (currentSize < heap.size()) {
        heap[currentSize] = x;
    }
    else
        heap.push_back(x);
    siftUp(currentSize);
    currentSize++;
}
void MinHeap::Remove(int& x) {
    if (currentSize == 0)
        return;
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1);
}
MaxHeap::MaxHeap() {
    currentSize = 0;
}
void MaxHeap::siftDown(int start, int m) {
    int i = start, j = 2 * i + 1;
    int temp = heap[i];
    while (j <= m) {
        if (j < m && heap[j] < heap[j + 1])
            j++;
        if (temp >= heap[j])
            break;
        else {
            heap[i] = heap[j];
            i = j;
            j = j * 2 + 1;
        }
    }
    heap[i] = temp;
}
void MaxHeap::siftUp(int start) {
    int j = start, i = (j - 1) / 2;
    int temp = heap[j];
    while (j > 0) {
        if (heap[i] >= temp)
            break;
        else {
            heap[j] = heap[i];
            j = i;
            i = (i - 1) / 2;
        }
    }
    heap[j] = temp;
}
void MaxHeap::Insert(int x) {
    if (currentSize < heap.size()) {
        heap[currentSize] = x;
    }
    else
        heap.push_back(x);
    siftUp(currentSize);
    currentSize++;
}
void MaxHeap::Remove(int& x) {
    if (currentSize == 0)
        return;
    x = heap[0];
    heap[0] = heap[currentSize - 1];
    currentSize--;
    siftDown(0, currentSize - 1);
}

class MedianFinder {
private:
    MaxHeap maxh;
    MinHeap minh;
    int midValue;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        midValue = INT_MIN;
    }

    void addNum(int num) {
        if (maxh.CurrentSize() == 0 && minh.CurrentSize() == 0 && midValue == INT_MIN)
            midValue = num;
        else {
            if (num > midValue)
                minh.Insert(num);
            else
                maxh.Insert(num);
            if (minh.CurrentSize() == (maxh.CurrentSize() + 2)) {
                maxh.Insert(midValue);
                minh.Remove(midValue);
            }
            else if (maxh.CurrentSize() > minh.CurrentSize()) {
                minh.Insert(midValue);
                maxh.Remove(midValue);
            }
        }
    }

    double findMedian() {
        if (maxh.CurrentSize() == minh.CurrentSize())
            return (double)midValue;
        else
            return ((double)midValue + minh.min()) / 2;
    }
};

int main() {
    MedianFinder sol;
    sol.addNum(4);
    sol.addNum(2);
    int x = sol.findMedian();
    sol.addNum(3);
    sol.addNum(1);
    int y = sol.findMedian();
    return 0;
}