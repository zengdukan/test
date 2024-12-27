/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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

#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;

        queue<TreeNode*> v;
        if (root != NULL)
            v.push(root);
        while (!v.empty()) {
            int size = v.size();
            vector<int> levelRet;
            while (size-- > 0) {
                auto node = v.front();
                v.pop();
                levelRet.push_back(node->val);
                if (node->left)
                    v.push(node->left);
                if (node->right)
                    v.push(node->right);
            }

            ret.push_back(levelRet);
        }

        return ret;
    }
};
// @lc code=end

