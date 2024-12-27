/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

#include <set>
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1) return 1;

        set<int64_t> uglyNums;
        uglyNums.insert(1);

        while (uglyNums.size() > 0) {
            int64_t ugly = *uglyNums.begin();
            uglyNums.erase(uglyNums.begin());
            if (--n <= 0) {
                return ugly;
            }
            uglyNums.insert(ugly * 2);
            uglyNums.insert(ugly * 3);
            uglyNums.insert(ugly * 5);


        }

        return 0;
    }
};
// @lc code=end

