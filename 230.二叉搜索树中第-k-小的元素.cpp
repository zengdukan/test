/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第 K 小的元素
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ret;
        int idx = 0;
        dfs(root, k, ret, idx);

        return ret;
    }

    void dfs(TreeNode* root, int k, int& result, int& idx) {
        if (root == nullptr)
            return;

        if (root->left)
            dfs(root->left, k, result, idx);

        idx++;
        if (k == idx) {
            result = root->val;
            return;
        }

        if (root->right)
            dfs(root->right, k, result, idx);
    }
};
// @lc code=end

