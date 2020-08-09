```cpp
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
    ListNode* sortList(ListNode* head) {
        ListNode *cur = head;

        while (head) {
            ListNode *t = head, *m = head;
            while (t->next) {
                if (t->next->val < m->val) {
                    m = t->next;
                }
                t = t->next;
            }
            int tmp = m->val;
            m->val = head->val;
            head->val = tmp;

            head = head->next;
        }

        return cur;
    }
};
```