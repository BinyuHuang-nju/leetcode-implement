#include <iostream>
using namespace std;
#include <vector>

class Solution1 { //exceeds time limitation
public:
    vector<int> countSmaller(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len, 0);
        int i, j;
        for (i = len - 2; i >= 0; i--) {
            for (j = i + 1; j < len; j++)
                if (nums[i] > nums[j])
                    res[i] += 1;
        }
        return res;
    }
};

class Solution_false {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> index(nums.size());
        for (int i = 0; i < nums.size(); i++)
            index[i] = i;
        quicksort(nums, index, 0, nums.size() - 1);
        vector<int> res;
        /*    */
        return res;
    }
private:
    void quicksort(vector<int>& nums, vector<int>& index, int start, int end) {
        if (start < end) {
            int pivot = partition(nums, index, start, end);
            quicksort(nums, index, start, pivot - 1);
            quicksort(nums, index, pivot + 1, end);
        }
    }
    int partition(vector<int>& nums, vector<int>& index, int start, int end) {
        int pivot = nums[end];
        int i = start;
        for (int j = start; j < end; j++) {
            if (nums[j] < pivot) {
                swap(nums[i], nums[j]);
                swap(index[i], index[j]);
                i++;
            }
        }
        if (i != end) {
            swap(nums[i], nums[end]);
            swap(index[i], index[end]);
        }
        return i;
    }
    void swap(int& x, int& y) {
        int temp = x;
        x = y;
        y = temp;
    }
};

class Solution {
private:
    struct TreeNode {
        int leftcount;
        int val;
        TreeNode* left, * right;
        TreeNode(int x) :leftcount(0), val(x), left(NULL), right(NULL) {}
    };
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res(nums.size(), 0);
        if (nums.size() == 0)
            return res;
        TreeNode* root = new TreeNode(nums[nums.size() - 1]);
        for (int i = nums.size() - 2; i >= 0; i--) {
            addNode(res, root, nums[i], i);
        }
        return res;
    }
    TreeNode* addNode(vector<int>& res, TreeNode* root, int val, int index) {
        if (!root)
            root = new TreeNode(val);
        else {
            if (val <= root->val) {
                root->leftcount++;
                root->left = addNode(res, root->left, val, index);
            }
            else {
                res[index] += root->leftcount + 1;
                root->right = addNode(res, root->right, val, index);
            }
        }
        return root;
    }
};
int main() {
    vector<int> a = { 5,2,6,1 };
    Solution sol;
    vector<int> b = sol.countSmaller(a);
    return 0;
}