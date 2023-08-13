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
    ListNode* removeElements(ListNode*, int);
};

ListNode* Solution::removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy;
    ListNode* cur = head;
    ListNode* tmp;

    while (cur)
        if (cur->val == val) {
            cur = cur->next;
            tmp = prev->next;
            prev->next = cur;
            delete tmp;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    
    head = dummy->next;
    delete dummy;

    return head;
}
