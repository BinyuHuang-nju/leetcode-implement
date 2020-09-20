#include <iostream>
using namespace std;
#include <vector>

class Solution {
private:
    struct Node {
        vector<int> point;
        int distance;
    };
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        if (K >= points.size())
            return points;
        vector<vector<int>> results;
        if (K == 0)
            return results;
        vector<Node> pp(points.size());
        for (int i = 0; i < points.size(); i++) {
            pp[i].point = points[i];
            pp[i].distance = points[i][0] * points[i][0] + points[i][1] * points[i][1];
        }
        select_elinear(pp, 0, points.size()-1, K);
        for (int i = 0; i < K; i++)
            results.push_back(pp[i].point);
        return results;
    }
    int partition(vector<Node>& pp, int start, int end) {
        Node pivot = pp[end];
        int i = start;
        for (int j = start; j < end; j++) {
            if (pp[j].distance < pivot.distance) {
                Node temp = pp[i];
                pp[i] = pp[j];
                pp[j] = temp;
                i++;
            }
        }
        Node temp = pp[i];
        pp[i] = pp[end];
        pp[end] = temp;
        return i;
    }
    void select_elinear(vector<Node>& pp, int p, int r, int k) {
        if (p == r)
            return;
        int q = partition(pp, p, r);
        int x = q - p + 1;
        if (k == x)
            return;
        else if (k < x)
            select_elinear(pp, p, q - 1, k);
        else
            select_elinear(pp, q + 1, r, k - x);
    }
};
int main() {
    Solution sol;
    vector<vector<int>> a = { {1,3},{-2,2} };
    vector<vector<int>> re=sol.kClosest(a, 1);
    return 0;
}