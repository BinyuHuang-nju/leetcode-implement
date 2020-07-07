#include <iostream>
using namespace std;
#include <vector>

class Solution {
public:
    string pushDominoes(string dominoes) {
        string results = dominoes;
        bool haveR = false, haveL = false;
        int indexR = -1, indexL = -1;
        int i, j, k;
        for ( i = 0; i < dominoes.length(); i++) {
            if (i == dominoes.length() - 1 && haveR && dominoes[i] != 'L') {
                for ( j = indexR + 1; j < dominoes.length(); j++)
                    results[j] = 'R';
                break;
            }
            if (dominoes[i] == 'R') {
                if (haveR) {
                    for ( j = indexR + 1; j < i; j++)
                        results[j] = 'R';
                    indexR = i;
                }
                else {
                    haveR = true;
                    indexR = i;
                    if (haveL)
                        haveL = false;
                }
            }
            else if (dominoes[i] == 'L') {
                if (haveL) {
                    for ( j = indexL + 1; j < i; j++)
                        results[j] = 'L';
                    indexL = i;
                }
                else if (!haveR) {
                    for ( j = 0; j < i; j++)
                        results[j] = 'L';
                    haveL = true;
                    indexL = i;
                }
                else {      // !haveL && haveR
                    haveL = true;
                    indexL = i;
                    for (j = indexR + 1, k = indexL - 1; j < k; j++, k--) {
                        results[j] = 'R';
                        results[k] = 'L';
                    }
                    haveR = false;
                }
            }
        }
        return results;
    }
};