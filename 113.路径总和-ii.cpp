/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
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
    struct Item {
        vector<int> path;
        int sum;
        TreeNode* node;
    };
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;

        stack<Item> _stack;
        _stack.push({{root->val}, root->val, root});
        while (!_stack.empty()) {
            Item item = _stack.top();
            _stack.pop();

            if (item.node->left == NULL && item.node->right == nullptr && item.sum == targetSum) {
                ret.push_back(item.path);
            }

            TreeNode* right = item.node->right;
            if (right != nullptr) {
                Item ritem = item;
                ritem.path.push_back(right->val);
                ritem.sum += right->val;
                ritem.node = right;
                _stack.emplace(ritem);
            }

            TreeNode* left = item.node->left;
            if (left != nullptr) {
                Item litem = item;
                litem.path.push_back(left->val);
                litem.sum += left->val;
                litem.node = left;
                _stack.emplace(litem);
            }
        }

        return ret;
    }
};
// @lc code=end

