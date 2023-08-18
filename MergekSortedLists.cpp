// Time: O(N * (log K)), Where K is the number of linked lists, N is the number of nodes in two lists
// Space: O(K)

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
    ListNode* mergeKLists(vector<ListNode*>&);
private:
    ListNode* merge2Lists(ListNode*&, ListNode*&);
};

ListNode* Solution::merge2Lists(ListNode*& l1, ListNode*& l2) {
    ListNode* dummy = new ListNode();
    ListNode* tmp = dummy;

    while (l1 || l2) {
        if (!l2 || (l1 && l1->val <= l2->val)) {
            tmp->next = l1;
            l1 = l1->next;
        } else {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    tmp = dummy;
    dummy = dummy->next;
    delete tmp;
    return dummy;
}

ListNode* Solution::mergeKLists(vector<ListNode*>& lists) {
    if (!lists.size())
        return nullptr;
    vector<ListNode*> merged_lists;
    ListNode* l1;
    ListNode* l2;

    while (lists.size() > 1) {
        for (int i = 0; i < lists.size(); i += 2) {
            l1 = lists[i];
            l2 = i + 1 < lists.size() ? lists[i + 1] : nullptr;
            merged_lists.push_back(merge2Lists(l1, l2));
        }
        lists = merged_lists;
        merged_lists.clear();
    }
    return lists[0];
}
