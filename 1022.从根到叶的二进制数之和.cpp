/*
 * @lc app=leetcode.cn id=1022 lang=cpp
 *
 * [1022] 从根到叶的二进制数之和
 */

#include <stack>
using namespace std;

#define LOCAL 1
#if LOCAL
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
#endif

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
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        int total = 0;
        inorder_loop(root, sum, total);
        return total;
    }

    // void inorder(TreeNode* root, int sum, int& total) {
    //     if (root == NULL) {
    //         return;
    //     }

    //     sum = sum * 2 + root->val;
    //     if (root->left == NULL && root->right == NULL) {
    //         total += sum;
    //     }

    //     if (root->left != NULL)
    //         inorder(root->left, sum, total);
    //     if (root->right != NULL)
    //         inorder(root->right, sum, total);
    // }

    void inorder_loop(TreeNode* root, int sum1, int& total) {
        if (root == NULL)
            return;
        stack<std::pair<TreeNode*, int>> _stack;
        _stack.emplace(root, 0);
        while (!_stack.empty()) {
            auto [node, sum] = _stack.top();
            _stack.pop();

            sum = sum * 2 + node->val;
            if (node->right == NULL && node->left == NULL) {
                total += sum;
                sum = 0;
            }
            if (node->right)
                _stack.emplace(node->right, sum);
            if (node->left)
                _stack.emplace(node->left, sum);
        }
    }
};
// @lc code=end

