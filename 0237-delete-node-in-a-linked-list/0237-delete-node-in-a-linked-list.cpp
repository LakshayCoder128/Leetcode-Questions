/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode(int x) : val(x), next(NULL) {}
 *};
 */
class Solution
{
    public:
        void deleteNode(ListNode *node)
        {
           	//current node's address = address of the next node 
           	// simply avoiding the node in between
            *node = *node->next;
        }
};