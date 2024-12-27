/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

#include <vector>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> _stack;

        int idx_push = 0;
        for (int i = 0; i < popped.size(); i++) {
            while ((_stack.empty() || _stack.top() != popped[i]) && idx_push < pushed.size()) {
                _stack.push(pushed[idx_push++]);
            }

            // judge idx_push
            if (!_stack.empty() && _stack.top() != popped[i] && idx_push == pushed.size()) {
                return false;
            }

            // ==
            _stack.pop();
        }

        return _stack.empty();
    }
};
// @lc code=end

