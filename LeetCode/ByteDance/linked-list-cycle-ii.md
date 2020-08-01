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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head->next;

        do {
            fast = fast->next;
            if (!fast || !fast->next)
                return NULL;
            else {
                fast = fast->next;
            }
            slow = slow->next;
        } while (fast->val != slow->val);

        return slow;
    }
};
```