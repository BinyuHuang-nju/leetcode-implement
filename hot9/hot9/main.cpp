#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>
#include <string>

class Solution {
public:
    void DFS(string str) {
        if (str.empty()) {
            re.push_back(temp);
            return;
        }
        char number = str[0];
        string letters = hashtable[number];
        string sub = str.substr(1);
        for (int i = 0; i < letters.length(); i++) {
            temp.push_back(letters[i]);
            DFS(sub);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        
        if (digits.empty())
            return re;
        DFS(digits);
        return re;
    }
private:
    vector<string> re;
    map<char, string> hashtable = { {'2',"abc"},{'3',"def"},{'4',"ghi"},
    {'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"} };
    string temp;
};
int main() {
    string str;
    getline(cin, str);
    Solution sol;
    vector<string> result = sol.letterCombinations(str);
    return 0;
}