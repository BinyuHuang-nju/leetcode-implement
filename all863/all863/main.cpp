#include <iostream>
using namespace std;
#include <vector>
#include <map>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/* Solution1：
C++，hash+dfs
执行用时： 8 ms , 在所有 C++ 提交中击败了 74.92% 的用户
内存消耗： 13.1 MB , 在所有 C++ 提交中击败了 100.00% 的用户

使用hash表，表中仅存储target的祖先节点或target节点的信息，
location用于判断target位于某节点的何处，0代表target就是该节点，
1代表target位于该节点左子树，2代表target位于该节点右子树；
depth用于记录某节点与target之间的距离，注意，该节点一定是target或target祖先节点。
计算方法见computeDpeth函数。
对hash表中每个节点进行dfs。
若该节点就是target，进行dfs并存储距离自己距离为K的子节点；
若该节点是target的祖先节点，通过depth获得该祖先节点与target的距离，记为dis。
则：
若dis>K，不必考虑，因为该节点或该节点令一子树节点与target距离均大于K；
若dis==K，则将该祖先节点存储即可；
若dis<K，这时通过location获得祖先节点q处的另一侧没有target的子树，
设置调用节点为q的另一侧子节点，距离为K-dis-1，进行dfs。
(dis是该祖先节点到target的距离，1是该祖先节点到另一侧子节点的距离)
*/
class Solution1 {

private:
    map<TreeNode*, int> location; // -1:not child,0:me,1:left child,2:right child
    map<TreeNode*, int> depth;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root)
            return {};
        computeDepth(root, target);
        vector<int> results;
        for (map<TreeNode*, int>::iterator iter = location.begin(); iter != location.end(); iter++) {
            if (iter->second == 0) {
                increaseNode(results, iter->first, K);
            }
            else if (iter->second == 1) {
                int dis = INT_MAX;
                if (depth.count(iter->first))
                    dis = depth[iter->first];
                if (dis < K) {
                    increaseNode(results, iter->first->right, K - dis - 1);
                }
                else if (dis == K)
                    results.push_back(iter->first->val);
            }
            else if (iter->second == 2) {
                int dis = INT_MAX;
                if (depth.count(iter->first))
                    dis = depth[iter->first];
                if (dis < K)
                    increaseNode(results, iter->first->left, K - dis - 1);
                else if (dis == K)
                    results.push_back(iter->first->val);
            }
        }
        return results;
    }
private:
    void increaseNode(vector<int>& results, TreeNode* root, int distance) {
        if (!root)
            return;
        if (distance == 0)
            results.push_back(root->val);
        else {
            if (root->left)
                increaseNode(results, root->left, distance - 1);
            if (root->right)
                increaseNode(results, root->right, distance - 1);
        }
    }
    int computeDepth(TreeNode* root, TreeNode* target) {
        if (root == target) {
            location[root] = 0;
            depth[root] = 0;
            return 0;
        }
        if (!root->left && !root->right) {
            //location[root] = -1;
            return -1;
        }
        int num1 = -2, num2 = -2;
        if (root->left) {
            num1 = computeDepth(root->left, target);
        }
        if (root->right) {
            num2 = computeDepth(root->right, target);
        }
        if (num1 >= 0) {
            location[root] = 1;
            depth[root] = num1 + 1;
            return (num1 + 1);
        }
        if (num2 >= 0) {
            location[root] = 2;
            depth[root] = num2 + 1;
            return (num2 + 1);
        }
        return -1;
    }
};


/* Solution2:
C++ hash+dfs
执行用时：4 ms, 在所有 C++ 提交中击败了94.27%的用户
内存消耗：9.9 MB, 在所有 C++ 提交中击败了100.00%的用户
沿用Solution1的思想，用location记录某节点是否为target的祖先节点，若是，
target在其左子树还是右子树中或是其本身。
这里将这些location中记录的祖先节点进行变换，使target成为变换后的树的根节点。
这里在交换(changeChild)前先调用一次increaseNode，之后再调用一次，原因在于：
在最坏情况下，target本身有两个非空子节点，再加上变换后，其父节点也成为了
它的子节点，那么target会有三个子节点，在不改变数据结构的情况下，节点无法
存放，因此这里直接先计算target的子树中距离target为K的节点，并将target的子树全部丢弃，
即target仅保留其父节点作为它的新的子节点。随后再调用increaseNode便不会出错。
但值得注意的是，在K为0的特殊情况下，则target会被写入两次，因此首先把K=0
情况交代。
*/
class Solution2 {

private:
    map<TreeNode*, int> location; // -1:not child,0:me,1:left child,2:right child
    //map<TreeNode*, TreeNode*> child;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (!root)
            return {};
        if (K == 0)
            return { target->val };
        isAncestry(root, target);
        vector<int> results;
        increaseNode(results, target, K);
        changeChild(root, NULL);
        increaseNode(results, target, K);
        return results;
    }
private:

    void changeChild(TreeNode* root,TreeNode* parent) {
        if (!root)
            return;
        if (!location.count(root) || location[root] < 0)
            return;
        if (location[root] == 0) {
            root->right = NULL;
            root->left = parent;
        }
        else if (location[root] == 1) {
            changeChild(root->left, root);
            root->left = parent;
        }
        else if (location[root] == 2) {
            changeChild(root->right, root);
            root->right = parent;
        }
    }
    void increaseNode(vector<int>& results, TreeNode* root, int distance) {
        if (!root)
            return;
        if (distance == 0)
            results.push_back(root->val);
        else {
            if (root->left)
                increaseNode(results, root->left, distance - 1);
            if (root->right)
                increaseNode(results, root->right, distance - 1);
        }
    }
    bool isAncestry(TreeNode* root, TreeNode* target) {
        if (root == target) {
            location[root] = 0;
            return true;
        }
        if (!root->left && !root->right) {
            //location[root] = -1;
            return false;
        }
        bool haveTarget1 = false, haveTarget2 = false;
        if (root->left) {
            haveTarget1 = isAncestry(root->left, target);
        }
        if (root->right) {
            haveTarget2 = isAncestry(root->right, target);
        }
        if (haveTarget1) {
            location[root] = 1;
            return true;
        }
        if (haveTarget2) {
            location[root] = 2;
            return true;
        }
        return false;
    }
};