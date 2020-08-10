/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 边界条件：
// 修改的是头指针
class Solution {
public:
    int solve(ListNode*& head, int n) {
        if (!head->next)
            return 1;
        int ret = solve(head->next, n);
        if (ret == n) {
            head->next = head->next->next;
        }
        return ret+1;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head)
            return NULL;
        int ret = solve(head, n);
        return (ret==n) ? head->next : head;
    }
};