/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
vector<vector<int>> result; //用于存答案
vector<int> path; //存路径
  
    void backtracking(const vector<int>& candidates, int target, int index, int sum)
    {
        if (sum == target) {
            result.push_back(path);
            return;
        }
        if (sum > target) return;
        for (int i = index; i < candidates.size(); i++) {
            path.push_back(candidates[i]);
            sum += candidates[i];

            backtracking(candidates, target, i, sum);

            sum -= candidates[i];
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        backtracking(candidates, target, 0, 0);
        return result;
    }
};
// @lc code=end

