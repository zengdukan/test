/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
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
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        dfs(root);
    }

    TreeNode* dfs(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        root->left = nullptr;
        root->right = dfs(left);
        if (root->right == nullptr) {
            root->right = dfs(right);
        } else {
            TreeNode* it = root->right;
            while (it && it->right) {
                it = it->right;
            }
            it->right = dfs(right);
        }

        return root;;
    }
};
// @lc code=end

