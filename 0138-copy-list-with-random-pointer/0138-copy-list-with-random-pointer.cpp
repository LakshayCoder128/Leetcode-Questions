// Include the class Node definition here

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // Step 1: Duplicate nodes and insert them into the original list.
        Node* current = head;
        while (current) {
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        // Step 2: Adjust random pointers of copied nodes.
        current = head;
        while (current) {
            if (current->random) {
                current->next->random = current->random->next;
            }
            current = current->next->next;
        }

        // Step 3: Split the merged list into two separate lists.
        current = head;
        Node* newHead = head->next;
        Node* newCurrent = newHead;
        while (current) {
            current->next = newCurrent->next;
            current = current->next;
            if (current) {
                newCurrent->next = current->next;
                newCurrent = newCurrent->next;
            }
        }

        return newHead;
    }
};