/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* hdr = new ListNode;
        ListNode* last = hdr;
        int n = 0;
        while (l1 != nullptr || l2 != nullptr) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + n;
            n = sum / 10;
            ListNode* node = new ListNode(sum % 10);
            last->next = node;
            last = node;
            if (l1)
                l1 = l1->next;
            if (l2)
                l2 = l2->next;
        }

        if (n > 0) {
            ListNode* node = new ListNode(n);
            last->next = node;
            last = node;
        }

        return hdr->next;
    }
};
// @lc code=end

