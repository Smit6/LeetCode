class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* tmp = nullptr;
        while (cur)
        {
            //prev, cur, cur.next = cur, cur.next, prev;
            tmp = cur;
            cur = cur->next;
            tmp->next = prev;
            prev = tmp;
        }
        return prev;
    }
};