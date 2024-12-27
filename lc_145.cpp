/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <algorithm>
#include <cstddef>
#include <vector>
#include <stack>
using namespace std;

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorderTraversal_loop2(root, nodes);
        return nodes;
    }

    void postorderTraversal_loop2(TreeNode* root, vector<int>& ret) {
        if (root == nullptr)
            return;

        stack<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();

            ret.push_back(node->val);
            if (node->left)
                nodes.push(node->left);
            if (node->right)
                nodes.push(node->right);
        }

        std::reverse(ret.begin(), ret.end());
    }

    // void postorderTraversal_recursive(TreeNode* root, vector<int>& nodes) {
    //     if (root == NULL)
    //         return;
    //     if (root->left != NULL)
    //         postorderTraversal_recursive(root->left, nodes);
    //     if (root->right != NULL)
    //         postorderTraversal_recursive(root->right, nodes);
    //     nodes.push_back(root->val);
    // }

    void postorderTraversal_loop(TreeNode* root, vector<int>& nodes) {
        if (root == NULL)
            return;
        stack<TreeNode*> _stack;
        _stack.emplace(root);
        while (!_stack.empty()) {
            auto top = _stack.top();
            _stack.pop();
            nodes.push_back(top->val);
            if (top->left)
                _stack.push(top->left);
            if (top->right)
                _stack.push(top->right);
        }

        std::reverse(nodes.begin(), nodes.end());
    }
};
// @lc code=end

