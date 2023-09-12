/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    private:
        ListNode* Recursive(ListNode *head)
        {
            if (head == NULL || head->next == NULL) return head;
            ListNode *rev = Recursive(head->next);
            ListNode *ans = rev;
            while (ans->next != NULL) ans = ans->next;
            head->next = NULL;
            ans->next = head;
            return rev;
        }
    ListNode* stackSolution(ListNode *head)
    {
        /*T.C. O(N) S.C. O(N) */
        stack<int> st;
        for (ListNode *i = head; i != NULL; i = i->next) st.push(i->val);
        ListNode *t = head;
        while (!st.empty())
        {
            t->val = st.top();
            st.pop();
            t = t->next;
        }
        return head;
    }
    ListNode* betterRecursiveReverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL) return head;
        ListNode *rev = betterRecursiveReverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return rev;
    }
    ListNode* ThreePointerReverse(ListNode *head)
    {
        ListNode *pre = NULL;
        ListNode *curr = head;
        while (curr != NULL)
        {
            ListNode *nextNode = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nextNode;
        }
        return pre;
    }
    ListNode* usingXOR(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *pre = NULL;
        while (head != 0)
        {

            pre = (ListNode*)((uintptr_t) pre ^ (uintptr_t) head->next);
            head->next = (ListNode*)((uintptr_t) pre ^ (uintptr_t) head->next);
            pre = (ListNode*)((uintptr_t) pre ^ (uintptr_t) head->next);

            pre = (ListNode*)((uintptr_t) pre ^ (uintptr_t) head);
            head = (ListNode*)((uintptr_t) pre ^ (uintptr_t) head);
            pre = (ListNode*)((uintptr_t) pre ^ (uintptr_t) head);
        }

        return pre;
    }
    public:
        ListNode* reverseList(ListNode *head)
        {
           	// return stackSolution(head);
           	// return Recursive(head);
           	// return betterRecursiveReverseList(head);
           	// return ThreePointerReverse(head);
            return usingXOR(head);
        }
};