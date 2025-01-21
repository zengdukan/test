/*
 * @lc app=leetcode.cn id=381 lang=cpp
 *
 * [381] O(1) 时间插入、删除和获取随机元素 - 允许重复
 */
#include <unordered_map>
#include <vector>
#include <set>

using namespace std;

// @lc code=start
class RandomizedCollection {
public:
    vector<int> _vec;
    unordered_map<int, set<int>> _map;

    RandomizedCollection() {
        
    }
    
    bool insert(int val) {
        bool exist = _map.find(val) != _map.end();

        _vec.push_back(val);
        if (exist) {
            _map[val].insert(_vec.size() - 1);
        } else {
            _map[val] = set<int>{int(_vec.size()) - 1};
        }
        
        return !exist;
    }
    
    bool remove(int val) {
        if (_map.find(val) == _map.end())
            return false;

        auto& idxs = _map[val];
        int idx = *idxs.begin();
        if (idx != _vec.size() - 1) {
            int last = _vec.back();
            _vec[idx] = last;
            _map[last].insert(idx);
        }
        
        _vec.pop_back();
        idxs.erase(idx);
        if (idxs.empty()) {
            _map.erase(val);
        }
        return true;
    }
    
    int getRandom() {
        int idx = rand() % _vec.size();
        return _vec[idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

