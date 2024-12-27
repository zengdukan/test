/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <set>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> num_map = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> ret;
        string track;
        backtrack(digits, track, 0, num_map, ret);

        return ret;
    }

    void backtrack(string& digits, string& track, int index, unordered_map<char, string>& num_map, vector<string>& ret) {
        if (index == digits.size()) {
            ret.push_back(track);
            return;
        }

        char digit = digits[index];
        const string& letters = num_map.at(digit);


        for (int j = 0; j < letters.size(); j++) {

            track.push_back(letters[j]);

            backtrack(digits, track, index + 1, num_map, ret);

            track.pop_back();
        }
    }
};
// @lc code=end

