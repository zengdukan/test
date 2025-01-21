/*
 * @lc app=leetcode.cn id=380 lang=cpp
 *
 * [380] O(1) 时间插入、删除和获取随机元素
 */
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (_map.find(val) != _map.end())
            return false;

        _vec.push_back(val);
        _map[val] = _vec.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (_map.find(val) == _map.end())
            return false;

        int idx = _map[val];
        if (idx != (_vec.size() - 1)) {
            int last = _vec.back();
            _vec[idx] = last;
            _map[last] = idx;
        }
        
        _vec.pop_back();

        _map.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx = rand() % _vec.size();
        return _vec[idx];
    }

    unordered_map<int, int> _map;
    vector<int> _vec;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

