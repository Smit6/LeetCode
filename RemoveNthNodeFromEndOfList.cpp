// Time: O(N)
// Space: O(1)

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
    ListNode* removeNthFromEnd(ListNode*, int);
};

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* slow = dummy;
    ListNode* fast = dummy;

    while (n-- && fast->next)
        fast = fast->next;
    
    while (fast->next) {
        slow = slow->next;
        fast = fast->next;
    }

    ListNode* to_delete = slow->next;
    slow->next = slow->next->next;
    delete to_delete;

    to_delete = dummy;
    dummy = dummy->next;
    delete to_delete;

    return dummy;
}
