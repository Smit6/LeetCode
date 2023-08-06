class Solution
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
        ListNode* dummy = new ListNode();
        ListNode* tmp = dummy;

        while (list1 || list2)
        {
            if (list1 && (!list2 || list1->val <= list2->val))
            {
                tmp->next = list1;
                list1 = list1->next;
            }
            else
            {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }

        return dummy->next;
    }
};