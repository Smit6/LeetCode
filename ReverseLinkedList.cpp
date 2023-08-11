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
    ListNode* reverseList(ListNode*);
};

ListNode* Solution::reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    ListNode* tmp = nullptr;

    while (cur) {
        tmp = cur;
        cur = cur->next;
        tmp->next = prev;
        prev = tmp;
    }

    return prev;
}
