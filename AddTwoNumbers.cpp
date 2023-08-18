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
    ListNode* addTwoNumbers(ListNode*, ListNode*);
};

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* tmp = dummy;
    
    int carry = 0;
    int ans = 0;

    while (l1 && l2) {
        ans = l1->val + l2->val + carry;
        carry = ans / 10;
        tmp->next = new ListNode(ans % 10);
        tmp = tmp->next;
        l1 = l1->next;
        l2 = l2->next;
    }

    ListNode* l = l1 && !l2 ? l1 : l2;

    while (l) {
        ans = l->val + carry;
        carry = ans / 10;
        tmp->next = new ListNode(ans % 10);
        tmp = tmp->next;
        l = l->next;
    }

    if (carry) {
        tmp->next = new ListNode(carry);
    }

    tmp = dummy->next;
    delete dummy;
    return tmp;
}
