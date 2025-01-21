/*
 * @lc app=leetcode.cn id=134 lang=cpp
 *
 * [134] 加油站
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int n = gas.size();

        while (i < n) {
            int costs = 0;
            int gass = 0;
            int cnt = 0;
            while (cnt < n) {
                int j = (i + cnt) % n;
                costs += cost[j];
                gass += gas[j];

                if (costs > gass) {
                    break;
                }

                cnt++;
            }

            if (cnt == n) {
                return i;
            } else {
                i = i + cnt + 1;
            }
        }

        return -1;
    }
};
// @lc code=end

