class Solution {
public:
    void reorderList(ListNode* head) {
        // Reach halfway in the list
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        ListNode* prev = nullptr;
        ListNode* cur = slow->next;
        ListNode* tmp = nullptr;

        slow->next = nullptr;

        while (cur)
        {
            tmp = cur;
            cur = cur->next;
            tmp->next = prev;
            prev = tmp;
        }

        // Merge lists with reorder
        ListNode* first = head;
        ListNode* second = prev;
        ListNode* tmp_1 = nullptr;
        ListNode* tmp_2 = nullptr;
        
        while (second)
        {
            tmp_1 = first->next;
            tmp_2 = second->next;

            first->next = second;
            second->next = tmp_1;
            first = tmp_1;
            second = tmp_2;
        }
    }
};