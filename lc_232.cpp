/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() {

    }

    void in2out() {
        while (!_s_push.empty()) {
            _s_pop.push(_s_push.top());
            _s_push.pop();
        }
    }

    void push(int x) {
        _s_push.push(x);
    }
    
    int pop() {
        if (_s_pop.empty()) {
           in2out();
        }

        int v = _s_pop.top();
        _s_pop.pop();
        return v;
    }
    
    int peek() {
        if (_s_pop.empty()) {
            in2out();
        }

        int v = _s_pop.top();
        return v;
    }
    
    bool empty() {
        return _s_push.empty() && _s_pop.empty();
    }
private:
    stack<int> _s_push;
    stack<int> _s_pop;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

