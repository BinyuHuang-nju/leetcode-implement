#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <map>
class Solution1 {
private:
    map<int, int> steps;
    int compute_steps(int x) {
        if (steps.count(x))
            return steps[x];
        int count = 0, tag = x;
        while (x != 1) {
            if (x % 2 == 0)
                x = x / 2;
            else
                x = 3 * x + 1;
            count++;
        }
        steps[tag] = count;
        return count;
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> table;
        for (int x = lo; x <= hi; x++) {
            compute_steps(x);
            table.push_back(make_pair(x, steps[x]));
        }
        sort(table.begin(), table.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
            });
        return table[k - 1].first;
    }
};
class Solution2 {
private:
    map<int, int> steps;
    int compute_steps(int x) {
        if (steps.count(x))
            return steps[x];
        if (x == 1)
            return steps[1] = 0;
        if (x % 2 == 0)
            return steps[x]= 1 + compute_steps(x / 2);
        return steps[x] = 1 + compute_steps(3 * x + 1);
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> table;
        for (int x = lo; x <= hi; x++) {
            compute_steps(x);
            table.push_back(make_pair(x, steps[x]));
        }
        sort(table.begin(), table.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if (a.second != b.second) return a.second < b.second;
            return a.first < b.first;
            });
        return table[k - 1].first;
    }
};
class Solution {
private:
    map<int, int> steps;
    int compute_steps(int x) {
        if (steps.count(x))
            return steps[x];
        if (x == 1)
            return steps[1] = 0;
        if (x % 2 == 0)
            return steps[x] = 1 + compute_steps(x / 2);
        return steps[x] = 1 + compute_steps(3 * x + 1);
    }
public:
    int getKth(int lo, int hi, int k) {
        vector<pair<int, int>> table;
        for (int x = lo; x <= hi; x++) {
            compute_steps(x);
            table.push_back(make_pair(x, steps[x]));
        }
        select_elinear(table, 0, hi - lo, k);
        return table[k - 1].first;
    }
private:
    int partition(vector<pair<int, int>>& table, int p, int r) {
        pair<int, int> pivot = table[r];
        int i = p;
        for (int j = p; j < r; j++) {
            if (table[j].second < pivot.second || (table[j].second == pivot.second && table[j].first < pivot.first)) {
                swap(table[i], table[j]);
                i++;
            }
        }
        swap(table[i], table[r]);
        return i;
    }
    void select_elinear(vector<pair<int, int>>& table, int p, int r, int k) {
        if (p == r)
            return;
        int q = partition(table, p, r);
        int x = q - p + 1;
        if (k == x)
            return;
        else if (k < x)
            select_elinear(table, p, q - 1, k);
        else
            select_elinear(table, q + 1, r, k - x);
    }
};

int main() {
    Solution sol;
    int x = sol.getKth(12, 15, 2);
    return 0;
}