/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorderTraversal_loop2(root, ans);
        return ans;
    }

    void inorderTraversal_loop2(TreeNode* root, vector<int>& ans) {
        if (root == nullptr)
            return;

        stack<pair<TreeNode*, bool>> nodes;
        nodes.emplace(root, false);

        while (!nodes.empty()) {
            auto node_flag = nodes.top();
            nodes.pop();

            auto node = node_flag.first;
            auto flag = node_flag.second;
            if (!flag) {
                if (node->right)
                    nodes.emplace(node->right, false);

                nodes.emplace(node, true);

                if (node->left)
                    nodes.emplace(node->left, false);
            } else {
                ans.push_back(node->val);
            }
        }
    }

    void inorderTraversal_recursive(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        inorderTraversal_recursive(root->left, ans);
        ans.push_back(root->val);
        inorderTraversal_recursive(root->right, ans);
    }

    void inorderTraversal_loop(TreeNode* root, vector<int>& ans) {
        if (root == NULL)
            return;
        stack<pair<TreeNode*, bool>> _stack;
        _stack.emplace(root, false);
        while(!_stack.empty()) {
            auto [top, flag] = _stack.top();
            _stack.pop();
            
            if (flag) ans.push_back(top->val);
            else {
                if (top->right)
                    _stack.emplace(top->right, false);
                _stack.emplace(top, true);
                if (top->left)
                    _stack.emplace(top->left, false);
            }
        }
    }
};
// @lc code=end

