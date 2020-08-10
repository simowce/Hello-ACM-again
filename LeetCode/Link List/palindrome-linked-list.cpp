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
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;
        vector<int> array;
        while (head) {
            array.push_back(head->val);
            head = head->next;
        }
        for (int i=0; i<=array.size()/2; i++) {
            if (array[i] != array[array.size()-1-i])
                return false;
        }
        return true;
    }
};