#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <string>

class Solution {
private:
    struct Coordinate {
        int x;
        int y;
    };
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        map<string, int> obstacle_table;
        string temp;
        for (vector<int> obstacle : obstacles) {
            temp = to_string(obstacle[0]) + "," + to_string(obstacle[1]);
            obstacle_table[temp] = 1;
        }
        int max = 0;
        int direction = 0; //0:north,1:east,2:south,3:west
        Coordinate start, end;
        start.x = start.y = 0;
        for (int command : commands) {
            if (command == -2)
                direction = (direction + 3) % 4;
            else if (command == -1)
                direction = (direction + 1) % 4;
            else {
                if (direction == 0) {
                    end.x = start.x;
                    end.y = start.y + command;
                    for (int i = start.y + 1; i <= end.y; i++) {
                        temp = to_string(start.x) + "," + to_string(i);
                        if (obstacle_table.count(temp)) {
                            end.y = i - 1;
                            break;
                        }
                    }
                }
                else if (direction == 1) {
                    end.y = start.y;
                    end.x = start.x + command;
                    for (int i = start.x + 1; i <= end.x; i++) {
                        temp = to_string(i) + "," + to_string(start.y);
                        if (obstacle_table.count(temp)) {
                            end.x = i - 1;
                            break;
                        }
                    }
                }
                else if (direction == 2) {
                    end.x = start.x;
                    end.y = start.y - command;
                    for (int i = start.y - 1; i >= end.y; i--) {
                        temp = to_string(start.x) + "," + to_string(i);
                        if (obstacle_table.count(temp)) {
                            end.y = i + 1;
                            break;
                        }
                    }
                }
                else {
                    end.y = start.y;
                    end.x = start.x - command;
                    for (int i = start.x - 1; i >= end.x; i--) {
                        temp = to_string(i) + "," + to_string(start.y);
                        if (obstacle_table.count(temp)) {
                            end.x = i + 1;
                            break;
                        }
                    }
                }
                max = (end.x * end.x + end.y * end.y) > max ? (end.x * end.x + end.y * end.y) : max;
                start = end;
            }
        }
        return max;
    }
};