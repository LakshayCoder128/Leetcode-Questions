/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
    public:
        Node* copyRandomList(Node *head)
        {
            if (head == NULL) return NULL;
            Node *ptr = head;
            while (ptr)
            {
                Node *newNode = new Node(ptr->val);
                newNode->next = ptr->next;
                ptr->next = newNode;
                ptr = newNode->next;
            }

            ptr = head;
            while (ptr != NULL)
            {
                ptr->next->random = (ptr->random != NULL) ? ptr->random->next : NULL;
                ptr = ptr->next->next;
            }

            Node *ptr_old_list = head;	// A->B->C
            Node *ptr_new_list = head->next;	// A'->B'->C'
            Node *head_old = head->next;
            while (ptr_old_list != NULL)
            {
                ptr_old_list->next = ptr_old_list->next->next;
                ptr_new_list->next = (ptr_new_list->next != NULL) ? ptr_new_list->next->next : NULL;
                ptr_old_list = ptr_old_list->next;
                ptr_new_list = ptr_new_list->next;
            }
            return head_old;
        }
};