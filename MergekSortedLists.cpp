class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (!lists.size()) return nullptr;
        vector<ListNode*> merged_lists;

        ListNode* l1;
        ListNode* l2;

        while (lists.size() > 1) {
            for (int i = 0; i < lists.size(); i += 2)
            {
                l1 = lists[i];
                l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
                merged_lists.push_back(merge2Lists(l1, l2));
            }
            lists = merged_lists;
            merged_lists.clear();
        }

        return lists[0];
    }
private:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode();
        ListNode* tmp = dummy;

        while (l1 || l2)
        {
            if (l1 && (!l2 || l1->val <= l2->val))
            {
                tmp->next = l1;
                l1 = l1->next;
            }
            else
            {
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }

        return dummy->next;
    }
};