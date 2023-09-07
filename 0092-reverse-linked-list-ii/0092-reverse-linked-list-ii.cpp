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
        ListNode* reverseBetween(ListNode *head, int m, int n)
        {
            if (head == NULL)
            {
                return NULL;
            }

           	// Move the two pointers until they reach the proper starting point
           	// in the list.
            ListNode *cur = head, *prev = NULL;
            while (m > 1)
            {
                prev = cur;
                cur = cur->next;
                m--;
                n--;
            }

           	// The two pointers that will fix the final connections.
            ListNode *con = prev, *tail = cur;

           	// Iteratively reverse the nodes until n becomes 0.
            ListNode *third = NULL;
            while (n > 0)
            {
                third = cur->next;
                cur->next = prev;
                prev = cur;
                cur = third;
                n--;
            }

           	// Adjust the final connections as explained in the algorithm
            if (con != NULL)
            {
                con->next = prev;
            }
            else
            {
                head = prev;
            }

            tail->next = cur;
            return head;
        }
};