/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

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

#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

#define LOCAL 0

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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;

        if (preorder.size() == 1 && inorder.size() == 1)
            return new TreeNode(preorder[0]);
        
        int root = preorder[0];
        auto root_iter = std::find(inorder.begin(), inorder.end(), root);
        vector<int> inorder_left(inorder.begin(), root_iter);
        vector<int> inorder_right(++root_iter, inorder.end());

        vector<int> preorder_left;
        vector<int> preorder_right;
        for (int i = 0; i < inorder_left.size(); i++) {
            preorder_left.push_back(preorder[i + 1]);
        }
        for (int i = inorder_left.size() + 1; i < preorder.size(); i++) {
            preorder_right.push_back(preorder[i]);
        }
        TreeNode* root_node = new TreeNode(root);
        root_node->left = buildTree(preorder_left, inorder_left);
        root_node->right = buildTree(preorder_right, inorder_right);
        return root_node;
    }
};
// @lc code=end

