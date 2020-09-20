#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <algorithm>

class Solution {
private:
    map<char,int> char_index;                     // index
    map<pair<int,int>, int> notequal;                     // not equal part
    vector<int> parent;                                // equal part
    int Find(int x) {
        while (parent[x] >= 0)
            x = parent[x];
        return x;
    }
    void Union(int x1, int x2) {
        int root1 = Find(x1), root2 = Find(x2);
        if (root1 != root2) {
            parent[root1] = parent[root1] + parent[root2];
            parent[root2] = root1;
        }
    }
public:
    bool equationsPossible(vector<string>& equations) {
        for (string equation : equations) {
            if (equation[0] == equation[3]) {
                if (equation[1] == '!')
                    return false;
                if (!char_index.count(equation[0])) {
                    char_index[equation[0]] = parent.size();
                    parent.push_back(-1);
                }
            }
            else {
                bool newchar = false;
                if (!char_index.count(equation[0])) {
                    newchar = true;
                    char_index[equation[0]] = parent.size();
                    parent.push_back(-1);
                }
                if (!char_index.count(equation[3])) {
                    newchar = true;
                    char_index[equation[3]] = parent.size();
                    parent.push_back(-1);
                }
                if (newchar) {
                    int root1 = Find(char_index[equation[0]]), root2 = Find(char_index[equation[3]]);
                    if (root1 > root2)
                        swap(root1, root2);
                    if (equation[1] == '=')
                        Union(root1, root2);
                    else {              
                        pair<int, int> s(root1, root2);
                        notequal[s] = 1;
                    }
                }
                else {
                    int root1 = Find(char_index[equation[0]]), root2 = Find(char_index[equation[3]]);
                    if (root1 > root2)
                        swap(root1, root2);
                    pair<int, int> s(root1, root2);
                    if (equation[1] == '=') {
                        if (root1 == root2)
                            continue;
                        if (notequal.count(s))
                            return false;
                        Union(root1, root2);
                    }
                    else {
                        if (root1==root2)
                            return false;
                        notequal[s] = 1;
                    }
                }
            }
        }
        return true;
    }
};
int main() {
    Solution sol;
    vector<string> a = { "b!=f","c!=e","f==f","d==f","b==f","a==f" };
    bool re= sol.equationsPossible(a);
    return 0;
}