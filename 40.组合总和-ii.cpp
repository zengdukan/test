/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, result, path, 0, 0);

        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& path, int sum, int index) {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        if (sum > target) {
            return;
        }

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtrack(candidates, target, result, path, sum, i + 1);

            path.pop_back();
            sum -= candidates[i];
        }
    }
};
// @lc code=end

