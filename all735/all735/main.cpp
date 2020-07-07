#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <stack>

class Solution1 {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> temp_results;
        bool collapsing = true;
        while (collapsing) {
            temp_results.clear();
            vector<int> ball_right, ball_left;
            for (int i = 0; i <= asteroids.size(); i++) {
                if (i == asteroids.size() || (asteroids[i] > 0 && !ball_left.empty())) {
                    while (!ball_right.empty() && !ball_left.empty()) {
                        if (ball_right[ball_right.size() - 1] + ball_left[0] > 0)
                            ball_left.erase(ball_left.begin());
                        else if (ball_right[ball_right.size() - 1] + ball_left[0] == 0) {
                            ball_right.pop_back();
                            ball_left.erase(ball_left.begin());
                        }
                        else
                            ball_right.pop_back();
                    }
                    if (!ball_right.empty()) {
                        for (int j = 0; j < ball_right.size(); j++)
                            temp_results.push_back(ball_right[j]);
                        ball_right.clear();
                    }
                    if (!ball_left.empty()) {
                        for (int j = 0; j < ball_left.size(); j++)
                            temp_results.push_back(ball_left[j]);
                        ball_left.clear();
                    }
                    if (i < asteroids.size())
                        ball_right.push_back(asteroids[i]);
                }
                else if (asteroids[i] > 0) {
                    if (ball_left.empty())
                        ball_right.push_back(asteroids[i]);
                    else {
                        // can not reach
                    }
                }
                else {
                    ball_left.push_back(asteroids[i]);
                }
            }
            if (temp_results.empty())
                return temp_results;
            bool end = true;
            for (int i = 0; i < temp_results.size() - 1; i++) { // int to unsigned int -1->2^32-1
                if (temp_results[i] > 0 && temp_results[i + 1] < 0)
                    end = false;
            }
            if (end)
                collapsing = false;
            asteroids.swap(temp_results);
        }
        return asteroids;
    }
};

class Solution2 {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        if (asteroids.empty())
            return asteroids;
        stack<int> master;
        master.push(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++) {
            if (master.empty()) {
                master.push(asteroids[i]);
            }
            else {              // (!master.empty())
                if (asteroids[i] > 0)
                    master.push(asteroids[i]);
                else {         // (!master.empty()&&asteroids[i]<0)
                    bool survive = true;
                    while (!master.empty() && master.top() > 0) {
                        int top = master.top();
                        if (top + asteroids[i] < 0)
                            master.pop();
                        else if (top + asteroids[i] == 0) {
                            master.pop();
                            survive = false;
                            break;
                        }
                        else {
                            survive = false;
                            break;
                        }
                    }
                    if (survive)
                        master.push(asteroids[i]);
                }
            }
        }
        stack<int> temp;
        vector<int> results;
        while (!master.empty()) {
            temp.push(master.top());
            master.pop();
        }
        while (!temp.empty()) {
            results.push_back(temp.top());
            temp.pop();
        }
        return results;
    }
};

int main() {
    Solution2 sol;
    vector<int> as = { -2,-1,1,2 };
    vector<int> re = sol.asteroidCollision(as);
    return 0;
}