#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    int numTilePossibilities(string tiles) {
        int result = 0;
        vector<bool> visited(tiles.length(), false);
        vector<char> chs;
        for (char ch : tiles)
            chs.push_back(ch);
        sort(chs.begin(), chs.end());
        traceback(result, chs, visited, 0);
        return result;
    }
    void traceback(int& result, vector<char>& tiles, vector<bool>& visited, int cur) {
        if (cur >= tiles.size())
            return;
        for (int i = 0; i < tiles.size(); i++) {
            if (!visited[i]) {
                result++;
                visited[i] = true;
                traceback(result, tiles, visited, cur + 1);
                visited[i] = false;
                while (i < tiles.size() - 1 && tiles[i] == tiles[i + 1])
                    i++;
            }
        }
    }
};