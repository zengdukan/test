/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

#include <map>
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        map<TreeNode*, TreeNode*> hm;
        vector<TreeNode*> ppath, qpath;

        dfs(root, nullptr, hm);
        TreeNode* iter = p;

        do {
            ppath.push_back(iter);
            // cout << iter->val << "\n";
            iter = hm[iter];
        } while (iter != nullptr);
        
        iter = q;
        do {
            qpath.push_back(iter);
            // cout << iter->val << "\n";
            iter = hm[iter];
        } while (iter != nullptr);

        int pidx = 0;
        int qindx = 0;
        if (ppath.size() > qpath.size()) {
            pidx = ppath.size() - qpath.size();
        } else {
            qindx = qpath.size() - ppath.size();
        }

        for (int i = pidx, j = qindx; i < ppath.size() && j < qpath.size(); i++, j++) {
            if (ppath[i] == qpath[j]) {
                return ppath[i];
            }
        }
        return nullptr;
    }

    void dfs(TreeNode* node, TreeNode* parent, map<TreeNode*, TreeNode*>& hm) {
        if (node == NULL)
            return;
        hm[node] = parent;
        dfs(node->left, node, hm);
        dfs(node->right, node, hm);
    }
};
// @lc code=end

