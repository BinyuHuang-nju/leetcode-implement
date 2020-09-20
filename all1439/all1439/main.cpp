#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
class Solution1 {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> last = mat[0];
        for (int i = 1; i < mat.size(); i++) {
            last = merge(last, mat[i], k);
        }
        return last[k - 1];
    }
private:
    vector<int> merge(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> results, tmp;
        for (int num1 : nums1) {
            for (int num2 : nums2)
                tmp.push_back(num1 + num2);
        }
        sort(tmp.begin(), tmp.end());
        int len = min((size_t)k, nums1.size() * nums2.size());
        results = vector<int>(tmp.begin(), tmp.begin() + len);
        return results;
    }
};

class Solution2 {
private:
    struct State {
        int sum;
        vector<int> pointers;
        State(int s, vector<int> p) :sum(s), pointers(p) {}
    };
    struct compare {
        bool operator()(State a, State b) {
            return a.sum > b.sum;
        }
    };
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat.front().size();
        int init_sum = 0;
        for (int i = 0; i < m; i++)
            init_sum += mat[i][0];
        vector<int> init_pointer(m, 0), last_pointer;
        int cur = 0;
        State init_state(init_sum, init_pointer);
        priority_queue<State, vector<State>, compare> pq;
        map<string, int> visited;
        pq.push(init_state);
        string sub = "";
        for (int i = 0; i < m; i++)
            sub += '0';
        visited[sub] = 1;
        State state(init_state);
        while (!pq.empty()) {
            state = pq.top();
            pq.pop();
            cur++;
            if (cur == k)
                break;
            last_pointer = state.pointers;
            for (int i = 0; i < m; i++) {
                if (last_pointer[i] == n - 1)
                    continue;
                vector<int> point = last_pointer;
                point[i] = point[i] + 1;
                string sub = "";
                for (int i = 0; i < m; i++)
                    sub += (char)(point[i] + '0');
                if (visited[sub] == 1)
                    continue;
                visited[sub] = 1;
                pq.push(State(state.sum - mat[i][last_pointer[i]] + mat[i][point[i]], point));
            }
        }
        return state.sum;
    }


};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat.front().size();
        int left = 0, right = 0;
        for (int i = 0; i < m; i++) {
            left += mat[i].front();
            right += mat[i].back();
        }
        int init = left;
        while (left < right) {
            int mid = (left + right) / 2;
            int cur = 1;
            dfs(mat, mid, 0, init, cur, k, m, n);
            if (cur >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    void dfs(vector<vector<int>>& mat, int mid, int index, int sum, int& cur, int k, int m, int n) {
        if (sum > mid || index == m || cur > k)
            return;
        dfs(mat,mid, index + 1, sum, cur, k, m, n);
        for (int i = 1; i < n; i++) {
            int tmp = sum + mat[index][i] - mat[index][0];
            if (tmp > mid)
                break;
            cur++;
            dfs(mat, mid, index + 1, tmp, cur, k, m, n);
        }
    }

};
int main() {
    vector<vector<int>> a = { {1,10,10},{1,4,5},{2,3,6} };
    Solution sol;
    sol.kthSmallest(a, 14);
}