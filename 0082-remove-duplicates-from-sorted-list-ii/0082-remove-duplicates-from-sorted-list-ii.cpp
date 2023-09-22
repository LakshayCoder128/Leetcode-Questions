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
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         ListNode* pre = NULL , *cur = head,*nxt = head->next;

//         while(cur != NULL){
//             if(cur == nxt){
//                 while(cur == nxt){
//                     cur = nxt;
//                     nxt = nxt->next;
//                 }
//                 if(pre != NULL)
//                 {pre ->next = nxt;cur = pre->next; nxt = nxt->next;}
//                 else {head = nxt; pre = NULL; cur = head;nxt = cur->next;}
//             }
//             else{
//                 pre = cur;
//                 cur = nxt;
//                 if(nxt)
//                     nxt = nxt ->next;
//             } 
//         }
//         return head;
//     }
// };
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)return head;
        set<int>st;
        for(ListNode* h = head;h->next!= NULL ;h=h->next){
            if(h->val == h->next->val){
                st.insert(h->val);
            }
        }
        ListNode*ans = new ListNode(0);
        ListNode*a = ans;
        
        for(ListNode* h = head;h!= NULL; h=h->next){
            if(st.find(h->val) == st.end()){
                ans->next = new ListNode(h->val) ;
                ans = ans->next;
            }
        }
       
        return a->next;
    }
};