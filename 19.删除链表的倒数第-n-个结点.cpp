/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

#define LOCAL 0
#if LOCAL
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
#endif


// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
         // n = 1
         // n = 5 head
        
        ListNode* iter = head;
        ListNode* noden = head;
        while (iter && n > 0) {
            iter = iter->next;
            n--;
        }

        if (iter == head || iter == NULL) {
            iter = head->next;
            delete head;
            return iter;
        }

        while (iter->next) {
            iter = iter->next;
            noden = noden->next;
        }

        iter = noden->next;
        noden->next = iter->next;
        delete iter;
        return head;
    }
};
// @lc code=end

