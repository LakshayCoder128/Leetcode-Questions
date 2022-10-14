/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* deleteMiddle(ListNode *head)
        {
           	//             if (head->next == NULL)
           	//             {
           	//                 return NULL;
           	//             }
           	//             ListNode *pre = head;
           	//             ListNode *slow = head;
           	//             ListNode *fast = head;
           	//             while (fast != NULL && fast->next != NULL)
           	//             {
           	//                 pre = slow;
           	//                 slow = slow->next;
           	//                 fast = fast->next;
           	//                 if (fast->next)
           	//                 {
           	//                     fast = fast->next;
           	//                 }
           	//             }

           	//             pre->next = slow->next;
           	//             delete(slow);
           	//             return head;

            if (head->next == NULL)
            {
                return NULL;
            }

            ListNode *slow = head;
            ListNode *fast = head->next->next;
            while (fast != NULL && fast->next != NULL)
            {
                slow = slow->next;
                fast = fast->next;
                if (fast->next)
                {
                    fast = fast->next;
                }
            }

            slow->next = slow->next->next;

            return head;
        }
};