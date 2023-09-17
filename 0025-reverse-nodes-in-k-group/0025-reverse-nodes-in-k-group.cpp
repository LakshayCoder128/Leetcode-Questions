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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next) return head;
        int len=0;
        ListNode*curr=head;
        while(curr)
        {
            curr=curr->next;
            len++;
        }

        if(k>len)
         return head;

        int K=k;

        ListNode*prev=NULL,*next;
        curr=head;
        while(curr and k--)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        if(curr)
            head->next=reverseKGroup(curr,K);
        return prev;
    }
};