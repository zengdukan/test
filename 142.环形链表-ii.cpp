/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && slow != nullptr) {
            if (fast == nullptr || fast->next == nullptr || slow == nullptr) {
                break;
            }
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                ListNode* iter = head;
                while (iter != slow) {
                    iter = iter->next;
                    slow = slow->next;
                }

                return iter;
            }
        } 

        return nullptr;
    }
};
// @lc code=end

