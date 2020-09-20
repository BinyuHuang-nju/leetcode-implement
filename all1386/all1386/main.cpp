#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
class Solution1 {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(), reservedSeats.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] != b[0]) return a[0] < b[0];
            return a[1] < b[1];
            });
        int result = 0;
        int visited = 0, peoples = reservedSeats.size();
        for (int i = 1; i <= n; i++) {
            bool remain[3] = { true,true,true };
            while (visited < peoples && reservedSeats[visited][0] == i) {
                if (reservedSeats[visited][1] >= 2 && reservedSeats[visited][1] <= 5)
                    remain[0] = false;
                if (reservedSeats[visited][1] >= 4 && reservedSeats[visited][1] <= 7)
                    remain[1] = false;
                if (reservedSeats[visited][1] >= 6 && reservedSeats[visited][1] <= 9)
                    remain[2] = false;
                visited++;
            }
            if (remain[0] && remain[2])
                result += 2;
            else if (remain[0] || remain[1] || remain[2])
                result += 1;
        }
        return result;
    }
};
class Solution2 {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> mp;
        for (vector<int> seat : reservedSeats) {
            if (!mp.count(seat[0]))
                mp[seat[0]] = 1 << (seat[1] - 1);
            else
                mp[seat[0]] |= (1 << (seat[1] - 1));
        }
        int a = 0b0000011110;
        int b = 0b0001111000;
        int c = 0b0111100000;
        int total = 0b0111111110;
        int result = 0;
        for (int i = 1; i <= n; i++) {
            if (!mp.count(i) || mp[i] == 0)
                result += 2;
            else {
                if ((mp[i] & total) == 0)
                    result += 2;
                else if ((mp[i] & a) == 0 || (mp[i] & b) == 0 || (mp[i] & c) == 0)
                    result += 1;
            }
        }
        return result;
    }
};

class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        map<int, int> mp;
        for (vector<int> seat : reservedSeats) {
            if (!mp.count(seat[0]))
                mp[seat[0]] = 1 << (seat[1] - 1);
            else
                mp[seat[0]] |= (1 << (seat[1] - 1));
        }
        int a = 0b0000011110;
        int b = 0b0001111000;
        int c = 0b0111100000;
        int total = 0b0111111110;
        int result = (n - mp.size()) * 2;
        for (auto m : mp) {
            if ((m.second & total) == 0)
                result += 2;
            else if ((m.second & a) == 0 || (m.second & b) == 0 || (m.second & c) == 0)
                result += 1;

        }
        return result;
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {3,1}, {1,2},{1,3},{1,8},{2,6},{3,10} };
    sol.maxNumberOfFamilies(3, a);
    return 0;
}