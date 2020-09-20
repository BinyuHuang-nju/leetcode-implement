#include <iostream>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>
#include<map>

class Solution1 { // true but exceeds time limitations.
private:
    int* parent;
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
    int largestComponentSize(vector<int>& A) {
        if (A.size() < 2)
            return A.size();
        parent = new int[A.size()];
        memset(parent, -1, A.size() * sizeof(int));
        sort(A.begin(), A.end());
        for (int i = 1; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                for (int k = 2; k <= A[j]; k++) {
                    if (A[j] % k == 0 && A[i] % k == 0) {
                        Union(j, i);

                        break;
                    }
                }
            }
        }
        int maxNum = 0;
        for (int i = 0; i < A.size(); i++) {
            if (parent[i] + maxNum < 0)
                maxNum = -parent[i];
        }
        delete[]parent;
        return maxNum;
    }
};

class Solution {   //true but exceeds time limitations
private:
    int* parent;
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
    int largestComponentSize(vector<int>& A) {
        if (A.size() < 2)
            return A.size();
        map<int, int> A_table;
        int maxNum = 0;
        for (int i = 0; i < A.size();i++) {
            A_table[A[i]] = i;
            if (maxNum < A[i])
                maxNum = A[i];
        }
        parent = new int[maxNum+1];
        memset(parent, -1, (maxNum + 1) * sizeof(int));
        vector<bool> is_prime(maxNum + 1, true);
        for (int i = 2; i <= maxNum; i++) {
            if (is_prime[i]) {
                for (int j = 2 * i; j <= maxNum; j += i) {
                    if (A_table.count(j))
                        Union(j, i);
                    is_prime[j] = false;
                }
            }
        }
        for (int i = 0; i <= maxNum; i++)
            cout << parent[i] << " ";
        cout << endl;
        vector<int> counter(A.size(), 0);
        for (int i = 0; i < A.size();i++) {
            if (parent[A[i]] < 0)
                counter[i]++;
            else
                counter[A_table[Find(A[i])]]++;
        }
        for (int i = 0; i < A.size(); i++)
            cout << counter[i] << " ";
        int maxResult = 1;
        for (int i = 0; i < A.size(); i++) {
            if (counter[i] > maxResult)
                maxResult = counter[i];
        }
        delete[]parent;
        return maxResult;
    }
};

int main() {
    Solution sol;
    vector<int> a = { 4,6,15,35 };
    int x=sol.largestComponentSize(a);
    return 0;
}