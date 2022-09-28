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
        int countNode(ListNode *head)
        {
            int count = 0;

            ListNode *temp = head;

            while (temp != NULL)
            {
                count++;
                temp = temp->next;
            }

            return count;
        }

    ListNode* removeNthFromEnd(ListNode *head, int n)
    {

        int node = countNode(head);

        ListNode *p = head;
        int delNode = node - n;

        if (delNode == 0) head = head->next;
        while (delNode > 1)
        {
            delNode--;
            p = p->next;
            cout << p->val << " " << delNode << endl;
        }

        if (p->next)
        {
            if (p->next->next)
            {
                p->next = p->next->next;
            }
            else
            {
                p->next = NULL;
            }
        }
        return head;
    }
};