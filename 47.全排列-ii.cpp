/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include <vector>
#include <set>
#include <string>
#include <sstream>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ret;
        set<string> ret_maps;
        vector<int> trace;
        set<int> path;
        backtrace(nums, ret, trace, path, ret_maps);
        return ret;
    }

    void backtrace(const vector<int>& nums, vector<vector<int>>& ret, vector<int>& trace, set<int>& path, set<string>& ret_maps) {
        if (trace.size() == nums.size()) {
            stringstream ss;
            for (auto it = trace.begin(); it != trace.end(); it++)
                ss << *it << ",";
            
            string key = ss.str();
            if (ret_maps.find(key) == ret_maps.end()) {
                ret.push_back(trace);
                ret_maps.insert(key);
            }
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (path.find(i) != path.end()) {
                continue;
            }

            trace.push_back(nums[i]);
            path.insert(i);
            backtrace(nums, ret, trace, path, ret_maps);
            trace.pop_back();
            path.erase(i);
        }
    }
};
// @lc code=end

