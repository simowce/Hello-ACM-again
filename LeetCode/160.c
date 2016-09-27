/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/*********************************解法一***************************************/
// 思路：
// 先遍历两个链表，算出各自的长度，然后将长的向前移动二者的长度的差值
// 这样，两个链表就是可以看作是长度相等了，然后各自向前移动，第一个遇到的相同的节点就是公共节点
// 如果遍历到底都没有，那么说明没有共同节点
void pre_run(struct ListNode **l, int num)
{
    while (num--)
        (*l) = (*l)->next;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    int len_a = 0;
    int len_b = 0;
    struct ListNode *ta = headA;
    struct ListNode *tb = headB;
    
    while (ta) {
        len_a++;
        ta = ta->next;
    }
    while (tb) {
        len_b++;
        tb = tb->next;
    }
    ta = headA;
    tb = headB;
    if (len_a > len_b)
        pre_run(&ta, len_a-len_b);
    else
        pre_run(&tb, len_b-len_a);
        
    while (ta && tb)
        if (ta == tb)
            return ta;
        else {
            ta = ta->next;
            tb = tb->next;
        }
        
    return NULL;
}

/************************************解法二**********************************************/
// 思路：
// 主要思路跟上面的一样，但是更加的优雅，还是通过去除两者的长度差来达到一同前进从而找到共同节点
// 做法是两个节点分别遍历两个链表，如果其中某一个达到了链表的结尾，那么就移到另外一个链表上
// 这样，长度短的会先移到长度长的，然后两者在长度长的链表向前移动二者的长度差
// 接着，长度长的节点到了长度长的结尾，移到长度短的链表的表头，这时候，两者已经是在同一起跑线上
// 继续遍历，如果两者到了相同的节点，那么这个就是公共节点，否则，同时到达表尾，说明没有共同节点

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *a, *b;
    
    a = headA;
    b = headB;
    if (a == NULL || b == NULL)
        return NULL;
    while (a || b) {
        if (a == NULL && b != NULL)
            a = headB;
        else if (b == NULL && a != NULL)
            b = headA;
        else if (a == NULL && b == NULL)
            return NULL;
        if (a == b)
            return a;
        a = a->next;
        b = b->next;
    }
}
