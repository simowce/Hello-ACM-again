```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 // 迭代版本
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *cur = head;

        while (cur) {
            ListNode *n = cur->next;
            cur->next = pre;
            pre = cur;
            cur = n;
        }

        return pre;
    }
};
// 递归版本
class Solution {
public:
    ListNode** reverseList(ListNode* head) {
        if (head->next) {
            ListNode **ret = reverseList(head->next);
            (*ret)->next = head;
        }
        return &head;
    }
};

```