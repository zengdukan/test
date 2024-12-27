/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> trace;
        backtrace(ret, 1, trace, n, k);
        return ret;
    }

    void backtrace(vector<vector<int>>& ret, int index, vector<int>& trace, int n, int k) {
        if (trace.size() == k) {
            ret.push_back(trace);
            return;
        }

        for (int i = index; i <= n; i++) {
            trace.push_back(i);
            backtrace(ret, i + 1, trace, n, k);
            trace.pop_back();
        }
    }
};
// @lc code=end

