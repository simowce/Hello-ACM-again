#include <stdlib.h>


  struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode *a, *t, *ans = NULL;
    int v, v1, v2, carry = 0;

    while (l1 || l2) {
        v1 = l1 ? l1->val : 0;
        v2 = l2 ? l2->val : 0;
        t = (struct ListNode *) malloc(sizeof(struct ListNode));
        v = v1 + v2 + carry;

        carry = v/10;
        t->val = v%10;
        t->next = NULL;

        if (!ans) {
            ans = a = t;
        } else {
            a = a->next = t;
        }

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    if (carry != 0) {
        t = (struct ListNode *) malloc(sizeof(sizeof(struct ListNode)));
        t->val = carry;
        t->next = NULL;
        a->next = t;
    }
    return ans;
}
