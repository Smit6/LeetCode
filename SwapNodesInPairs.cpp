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
    ListNode* swapPairs(ListNode*);
};

ListNode* Solution::swapPairs(ListNode* head) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* prev = dummy;
    ListNode* tmp = head;

    ListNode* p1;
    ListNode* p2;
    ListNode* nxt;

    while (tmp && tmp->next) {
        p1 = tmp;
        p2 = tmp->next;
        nxt = tmp->next->next;

        p1->next = nxt;
        p2->next = p1;
        prev->next = p2;

        prev = p1;
        tmp = nxt;
    }

    return dummy->next;
}
