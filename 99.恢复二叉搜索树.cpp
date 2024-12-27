/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 */

#include <cstddef>
#include <vector>
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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> nodes;
        dfs(root, nodes);

        TreeNode* first=nullptr;
        TreeNode* second=nullptr;
        int i = 0;
        for (; i < nodes.size() - 1; i++) {
            if (nodes[i]->val > nodes[i + 1]->val) {
                first = nodes[i];
                break;
            }
        }
        int j = i + 1;
        for (; j < nodes.size() - 1; j++) {
            if (nodes[j]->val > nodes[j + 1]->val) {
                second = nodes[j + 1];
                break;
            }
        }

        if (j >= (nodes.size() - 1)) {
            second = nodes[i + 1];
        }
        
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }

    void dfs(TreeNode* root, vector<TreeNode*>& nodes) {
        if (root == nullptr) {
            return;
        }

        if (root->left != nullptr)
            nodes.push_back(root->left);
        nodes.push_back(root);
        if (root->right != nullptr)
            nodes.push_back(root->right);
    }
};
// @lc code=end

