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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int promote = 0;
        ListNode *ans = NULL, *cur = NULL;
        
        while (l1 || l2 || promote) {
            int n1 = l1 ? l1->val : 0;
            int n2 = l2 ? l2->val : 0;
            
            ListNode *t = new ListNode();
            t->val = (n1+n2+promote)%10;
            promote = (n1+n2+promote)/10;
            t->next = NULL;
            
            if (!ans) {
                ans = cur = t;
            } else {
                cur->next = t;
                cur = cur->next;
            }
            
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return ans;
    }
};
```

跟合并两个链表的思路完全一样，核心就是 `while (l1 || l2)`，只不过现在需要考虑进位，所以需要加上一个新的条件：`while (l1 || l2 || promote)`