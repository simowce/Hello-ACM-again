这道题目之前做过，结果再次做时，立马就想了一个错误的想法。题目的要求说的很清楚：

> 合并两个升序链表，**新链表是通过拼接给定的两个链表的所有节点组成的**

结果我的思路是，将 l1 插入到 l2，结果代码写得很难看，而且得处理很多边界条件，最后还是没有过。

重新读了一下题目，最简单的思路就是题目说的，**合并两个链表到一个新的链表**。然后可以使用一个循环就直接解决，核心点就是循环的判断：

```cpp
while (l1 || l2) {
    int n1 = l1 ? l1->val : 100000; // 这里的 100000 就是代表一个特别大的值
    int n2 = l2 ? l2->val : 100000;
}
```

这样就可以在一个循环内将两个链表处理完。其中有一个边界条件特殊处理一下：

* 一开始新链表是空的，需要初始化

完整代码如下：

```cpp
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ans = NULL, *t = NULL;
        ListNode *t1 = l1, *t2 = l2;
        
        
        while (t1 || t2) {
            int n1 = t1 ? t1->val : 100000;
            int n2 = t2 ? t2->val : 100000;
            
            if (t) {
                t->next = n1<n2 ? t1 : t2;
                t = t->next;
            } else {
                t = ans = n1<n2 ? t1 : t2;
            }
            if (n1<n2)
                t1 = t1->next;
            else
                t2 = t2->next;
        }
        return ans;
    }
};
```