/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* solution1(ListNode *head)
        {
           	//    1000 Testcase outof 1200 overflow 
            ListNode *ans = new ListNode();
            ListNode * headA;
            unsigned long long int dig = 0;
            while (head)
            {
                dig *= 10;
                dig = dig + head->val;
                head = head->next;
            }
            dig *= 2;
            if (dig == 0)
            {
                return ans;
            }
            stack<int> st;
            while (dig)
            {
                st.push(dig % 10);
                dig = dig / 10;
            }
            headA = ans;
            while (!st.empty())
            {
                ans->next = new ListNode(st.top());
                st.pop();
                ans = ans->next;
            }
            return headA->next;
        }

    ListNode* solution2(ListNode* head){
        if(head->val > 4) {
        // will generate a carry -> so create a new node before head and assign it head
        head = new ListNode(0,head);
        }
        ListNode* node  = head;
        while(node){
            node->val = ((2*node->val) %10) ;
            if(node->next and node->next->val > 4) node->val ++;
            node = node->next;
        }
        return head;
    }
    ListNode* doubleIt(ListNode *head) {
        return solution2(head);
    }
};
// 6 6 6

/*
 1 6 6 6

*/