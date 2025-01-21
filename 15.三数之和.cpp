/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;

        // std::sort(nums.begin(), nums.end());
        quick_sort(nums, 0, nums.size() - 1);

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int l = i + 1;
            int r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    ret.push_back({nums[i], nums[l], nums[r]});

                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }

                    l++;
                    r--;
                } else if (sum < 0) {
                    l++;
                } else {
                    r--;
                }
            }
        
        }
        return ret;
    }

    void quick_sort(vector<int>& nums, int start, int end) {
        if (start >= end)
            return;

        int idx = partition(nums, start, end);
        quick_sort(nums, start, idx - 1);
        quick_sort(nums, idx + 1, end);
    }

    int partition(vector<int>& nums, int start, int end) {
        int key = nums[start];

        int low = start, high = end;
        while (low < high) {
            while (low < high && nums[high] >= key) {
                high--;
            }
            while (low < high && nums[low] <= key) {
                low++;
            }

            if (low < high) {
                std::swap(nums[low], nums[high]);
            }
        }

        std::swap(nums[start], nums[low]);
        return low;
    }

};
// @lc code=end

