/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

#include <vector>
#include <set>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        set<int> track_set;
        backtrack(nums, track, track_set);
        return res;
    }

    void backtrack(vector<int>& nums, vector<int>& track, set<int>& track_set) {
        if (track.size() == nums.size()) {
            res.push_back(track);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (track_set.count(nums[i]) != 0)
                continue;

            track.push_back(nums[i]);
            track_set.insert(nums[i]);

            backtrack(nums, track, track_set);
            
            track.pop_back();
            track_set.erase(nums[i]);
        }
    }
};
// @lc code=end

