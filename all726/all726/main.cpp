#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <stack>
#include <map>

//stack + hashtable
class Solution {
private:
    struct Atom {
        string tag;
        int count;
    };
public:
    string countOfAtoms(string formula) {
        if (formula.length() && formula[0] != '(')
            formula = "(" + formula + ")";
        stack<Atom> mainSt, subSt;
        int i = 0;
        int atom_start = 0, atom_end = 0;
        int num_start = 0, num_end = 0;
        Atom temp;
        while (i < formula.length()) {
            if (formula[i] == '(') {
                temp.tag = "(";
                temp.count = 0;
                mainSt.push(temp);
                i++;
            }
            else if (formula[i] >= 'A' && formula[i] <= 'Z') {
                atom_start = i;
                while (i + 1 < formula.length() && formula[i + 1] >= 'a' && formula[i + 1] <= 'z')
                    i++;
                atom_end = i;
                temp.tag = formula.substr(atom_start, atom_end - atom_start + 1);
                i++;
                if (formula[i] >= '0' && formula[i] <= '9') {
                    num_start = i;
                    while (i + 1 < formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9')
                        i++;
                    num_end = i;
                    i++;
                    temp.count = stoi(formula.substr(num_start, num_end - num_start + 1));
                }
                else {
                    temp.count = 1;
                }
                mainSt.push(temp);
            }
            else if (formula[i] == ')') {
                while (!mainSt.empty()) {
                    temp = mainSt.top();
                    mainSt.pop();
                    if (temp.tag != "(")
                        subSt.push(temp);
                    else {
                        break;
                    }
                }
                i++;
                int num = 1;
                if (i < formula.length() && formula[i] >= '0' && formula[i] <= '9') {
                    num_start = i;
                    while (i + 1 < formula.length() && formula[i + 1] >= '0' && formula[i + 1] <= '9')
                        i++;
                    num_end = i;
                    i++;
                    num = stoi(formula.substr(num_start, num_end - num_start + 1));
                }
                while (!subSt.empty()) {
                    temp = subSt.top();
                    subSt.pop();
                    temp.count = temp.count * num;
                    mainSt.push(temp);
                }
            }
        }
        map<string, int> table;
        while (!mainSt.empty()) {
            temp = mainSt.top();
            mainSt.pop();
            table[temp.tag] += temp.count;
        }
        string result;
        for (map<string, int>::iterator iter = table.begin(); iter != table.end(); iter++) {
            result = result + iter->first;
            if (iter->second > 1)
                result = result + to_string(iter->second);
        }
        return result;
    }
};