class Solution {
public:
    int component = -1;  // Initialize a component variable to keep track of the number of connected components.
    
    int findParent(vector<int>& parent, int x) {
        while (parent[x] != x)
            x = parent[parent[x]];
        return x;
    }
    
    bool validChild(int child, int x, vector<int>& parent) {
        if (parent[child] != child)  // If the child node already has a parent set, it has two parents, return false.
            return false;
        else {
            int y = findParent(parent, child);
            if (x != y) {
                parent[y] = x;
                component--;
            } else {
                return false;  // If (x == y), both belong to the same set, and there's a loop, return false.
            }
        }
        return true;
    }
    
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n);
        component = n;
        int root = -1;

        for (int i = 0; i < n; i++) {
            parent[i] = i;  // Assign each node as its parent.
        }

        for (int i = 0; i < n; i++) {
            int x = findParent(parent, i);  // Find the parent of the current root node if either of its children is present; we have to perform the union later.

            if (leftChild[i] != -1 || rightChild[i] != -1) {
                if (leftChild[i] != -1 && !validChild(leftChild[i], x, parent)) {
                    return false;
                }
                if (rightChild[i] != -1 && !validChild(rightChild[i], x, parent)) {
                    return false;
                }
            }
        }

        return component == 1;  // After all unions, there should be only one root.
    }
};