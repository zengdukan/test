/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> maps;
        for (int i = 0; i < nums.size(); i++) {
            maps[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            auto it = maps.find(target - nums[i]);
            if (it != maps.end() && it->second != i) {
                return vector<int>{i, it->second};
            }
        }

        return vector<int>();
    }
};
// @lc code=end

