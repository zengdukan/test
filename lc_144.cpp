/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

#include <cstddef>
#include <vector>
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorderTraversal_loop3(root, ret);
        return ret;
    }

    void preorderTraversal_loop3(TreeNode* root, vector<int>& ret) {
        if (root == nullptr)
            return;

        stack<TreeNode*> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            TreeNode* node = nodes.top();
            nodes.pop();

            ret.push_back(node->val);

            if (node->right)
                nodes.push(node->right);
            if (node->left)
                nodes.push(node->left);
        }
    }

    void preorderTraversal_recursive(TreeNode* root, vector<int>& ret) {
        if (root == NULL)
            return;
        ret.push_back(root->val);
        // preorderTraversal_recursive(root->left, ret);
        preorderTraversal_loop2(root->right, ret);
    }

    void preorderTraversal_loop1(TreeNode* root, vector<int>& ret) {
        if (root == NULL)
            return;
        stack<TreeNode*> _stack;
        _stack.push(root);
        while (!_stack.empty()) {
            auto node = _stack.top();
            _stack.pop();

            ret.push_back(node->val);
            if (node->right)
                _stack.push(node->right);
            if (node->left)
                _stack.push(node->left);
        }
    }

    void preorderTraversal_loop2(TreeNode* root, vector<int>& ret) {
        if (root == NULL)
            return;

        stack<pair<TreeNode*, bool>> _stack;
        _stack.emplace(root, false);
        while (!_stack.empty()) {
            auto [node, flag] = _stack.top();
            _stack.pop();

            if (flag)
                ret.push_back(node->val);
            else {
                if (node->right)
                    _stack.emplace(node->right, false);
                
                if (node->left)
                    _stack.emplace(node->left, false);

                _stack.emplace(node, true);
            }
        }
    }
};
// @lc code=end

