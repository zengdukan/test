/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

#include <algorithm>
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
    bool isBalanced(TreeNode* root) {
        int depth = 0;
        return dfs(root, depth);
    }

    bool dfs(TreeNode* root, int &depth) {
        if (root == nullptr) {
            depth = 0;
            return true;
        }

        int left_depth = 0;
        int right_depth = 0;
        bool left_ret = dfs(root->left, left_depth);
        bool right_ret = dfs(root->right, right_depth);
        depth = 1 + std::max(left_depth, right_depth);
        if (std::abs(left_depth - right_depth) > 1)
            return false;
        return left_ret && right_ret;
    }
};
// @lc code=end

