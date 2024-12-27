/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> empty;
        ret.push_back(empty);

        vector<int> path;
        backtrack(nums, ret, path, 0);
        return ret;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& ret, vector<int>& path, int idx) {
        if (idx >= nums.size())
            return;

        for (int i = idx; i < nums.size(); i++) {
            path.push_back(nums[i]);
            ret.push_back(path);

            backtrack(nums, ret, path, i + 1);

            path.pop_back();
        }
    }
};
// @lc code=end

