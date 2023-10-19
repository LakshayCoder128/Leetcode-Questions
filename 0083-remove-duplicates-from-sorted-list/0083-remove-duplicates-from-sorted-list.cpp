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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* ans = new ListNode(head->val);
        ListNode* an = ans;
        for(ListNode*t = head; t->next != NULL ; t= t->next){
            if(t->val != t->next->val){
                ans->next = new ListNode(t->next->val);
                ans = ans->next;
            }
        }
        return an;
    }
};