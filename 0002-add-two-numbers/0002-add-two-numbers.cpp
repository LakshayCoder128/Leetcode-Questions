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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    if (l1 == NULL and l2 == NULL) return NULL;
			else if (l1 == NULL) return l2; 
			else if (l2 == NULL) return l1; 

			int a = l1->val + l2->val;
			ListNode *p = new ListNode(a % 10);
			p->next = addTwoNumbers(l1->next,l2->next);
			if (a >= 10) p->next = addTwoNumbers(p->next, new ListNode(1));
			return p;
//     void solve(ListNode*&l1,ListNode*&l2,int &carry,ListNode* ans){
//         // base case
//         if(!l1->next && !l2->next ){
//             int sum = l1->val + l2->val + carry;
//             ans->val = sum%10;
//             carry = sum/10;
//             ans->next = new ListNode();
//             // ans = ans->next;
//             return;
//         }
        
//         if(l1->next && l2->next)solve(l1->next,l2->next,carry,ans);
//         else if (l1->next) solve(l1->next,l2,carry,ans);
//         else solve(l1,l2->next,carry,ans);
        
//         int sum = 0;
//         if(l1 && l2){
//             sum = l1->val+l2->val +carry;
//             ans->next = new ListNode(sum%10);
//             ans = ans->next;
//             carry = sum/10;
//             // ans = ans->next;

//         }
//         else if(l1 && !l2){
//             sum = l1->val+ +carry;
//             ans->next = new ListNode(sum%10);
//             carry = sum/10;
            
//         }
//         else{
//             sum = l2->val +carry;
//             ans->next = new ListNode(sum%10);
//             carry = sum/10;
//         }

        
//     }
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* ans = new ListNode();        
//         ListNode* p = ans;

//         int carry = 0;
//         solve(l1,l2,carry,ans);
//         if(carry > 0) {
//             ans->next = new ListNode(carry);
//         }
//         // ans->next = NULL;
        
//         return p;
    }
};