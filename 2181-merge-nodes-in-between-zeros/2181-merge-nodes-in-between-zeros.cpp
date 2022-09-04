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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ans = new ListNode();
        ListNode* t = head;
        ListNode* p = ans;
        int count =0;
         int sum ;
        while(t!=NULL){
            // cout<<t->val<<endl;
            if(t->val == 0) {
                // cout<<"Sum: "<<sum<<endl;
                if(count!=0){
                    p->next = new ListNode(sum);
                    p=p->next;
                }
                sum =0;
                count++;
            }
            else{
                // cout<<t->val<<endl;
                sum+= t->val;
            }
            
            t=t->next;
            
        }
        return ans->next;
    }
};