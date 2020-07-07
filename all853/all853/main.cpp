#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <stack>
class Solution {
private:
    struct Car {
        int position;
        double time;
    };
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if (position.size() < 2)
            return position.size();
        vector<Car> cars(position.size());
        for (int i = 0; i < position.size(); i++) {
            cars[i].position = position[i];
            cars[i].time = ((double)target - position[i]) / speed[i];
        }
        quicksort(cars, 0, position.size() - 1);
        /*
        queue<double> last_time;
        for (int i = 1; i < position.size(); i++) {
            if (cars[i - 1].time > cars[i].time) {
                last_time.push(cars[i - 1].time);
            }
            if (i == position.size() - 1)
                last_time.push(cars[i].time);
        }
        int result = 1;
        double last = last_time.front();
        last_time.pop();
        while (!last_time.empty()) {
            if (last > last_time.front()) {
                result++;
            }
            last = last_time.front();
            last_time.pop();
        }*/
        stack<double> last_time;
        for (int i = 1; i < position.size(); i++) {
            if (cars[i - 1].time > cars[i].time) {
                last_time.push(cars[i - 1].time);
            }
            if (i == position.size() - 1)
                last_time.push(cars[i].time);
        }
        int result = 1;
        double last = last_time.top();
        last_time.pop();
        while (!last_time.empty()) {
            if (last_time.top() > last) {
                result++;
                last = last_time.top();
            }
            last_time.pop();
        }
        return result;
    }
private:
    void quicksort(vector<Car>& cars, int start, int end) {
        if (start < end) {
            int pivot = partition(cars, start, end);
            quicksort(cars, start, pivot - 1);
            quicksort(cars, pivot + 1, end);
        }
    }
    int partition(vector<Car>& cars, int start, int end) {
        Car pivot = cars[end];
        int i = start;
        for (int j = start; j < end; j++) {
            if (cars[j].position < pivot.position) {
                swap(cars[i], cars[j]);
                i++;
            }
        }
        swap(cars[i], cars[end]);
        return i;
    }
    void swap(Car& x, Car& y) {
        Car temp = x;
        x = y;
        y = temp;
    }
};
int main() {
    vector<int> a = { 6,8 };
    vector<int> b = { 3,2 };
    Solution sol;
    sol.carFleet(10, a, b);
    return 0;
}