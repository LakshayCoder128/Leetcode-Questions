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
    int len(ListNode*h){
        int cnt = 0;
        while(h!=nullptr){
            cnt++;
            h = h->next;

        }
        return cnt;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next)return head;
        int size = len(head);
        k = k % size;
        while(k--){
            ListNode*h = head;
            int p = head->val;
            h = h->next;
            while(h != NULL){
                int v = h->val;
                h->val = p;
                p = v;
                h = h->next;
            }
            head->val = p;
        }

        return head;
    }
};