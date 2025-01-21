/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */
#include <vector>
using namespace std;


// @lc code=start
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lefts(nums.size(), 1);
        vector<int> rihgts(nums.size(), 1);

        for (int i = 1, j = nums.size() - 2; i < nums.size() && j >= 0; i++, j--) {
            lefts[i] = lefts[i - 1] * nums[i - 1];
            rihgts[j] = rihgts[j + 1] * nums[j + 1];
        }

        vector<int> ret(nums.size(), 1);
        for (int i = 0; i < nums.size(); i++) {
            ret[i] = lefts[i] * rihgts[i];
        }

        return ret;
    }
};
// @lc code=end

