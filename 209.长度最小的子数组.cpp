/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int high = 0;
        int low = 0;
        int sum = 0;
        int ret = INT_MAX;

        while (high < nums.size()) {
            sum += nums[high++];
            while (sum >= target) {
                ret = std::min(ret, high - low);
                sum -= nums[low++];
            }
        }

        return ret == INT_MAX ? 0 : ret;
    }

    
};
// @lc code=end

