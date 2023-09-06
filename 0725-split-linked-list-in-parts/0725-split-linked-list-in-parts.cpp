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
        vector<ListNode*> splitListToParts(ListNode *head, int k)
        {
            ListNode *cur = head;
            int N = 0;
            while (cur != NULL)
            {
                cur = cur->next;
                N++;
            }

            int width = N / k, rem = N % k;

            vector<ListNode*> ans(k);
            cur = head;
            for (int i = 0; i < k; ++i)
            {
                ListNode *head = new ListNode(0), *write = head;
                for (int j = 0; j < width + (i < rem ? 1 : 0); ++j)
                {
                    write = write->next = new ListNode(cur->val);
                    if (cur != NULL) cur = cur->next;
                }
                ans[i] = head->next;
            }
            return ans;
        }
};