class Solution {
public:
    // Helper function for Depth-First Search (DFS)
    int dfs(vector<int> &left, vector<int> &right, int root) {
        // If the current node is NULL, return 0 as there are no nodes in this subtree.
        if (root == -1) {
            return 0;
        }
        
        // Recursively count the nodes in the left and right subtrees and add 1 for the current node.
        return 1 + dfs(left, right, left[root]) + dfs(left, right, right[root]);
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        // Create a vector to keep track of the parent count for each node.
        vector<int> parentCount(n, 0);

        // Initialize the root node as -1 (no root yet).
        int root = -1;

        // Iterate through the child nodes.
        for (int i = 0; i < leftChild.size(); i++) {
            // Check the left child.
            if (leftChild[i] != -1) {
                // If a node has more than one parent, return false.
                if (parentCount[leftChild[i]]++ == 1) {
                    return false;
                }
            }

            // Check the right child.
            if (rightChild[i] != -1) {
                // If a node has more than one parent, return false.
                if (parentCount[rightChild[i]]++ == 1) {
                    return false;
                }
            }
        }

        // Find the root node and check for multiple roots.
        for (int i = 0; i < leftChild.size(); i++) {
            // If a node has no incoming edges (in-degree is 0) and has children, it's a candidate root.
            if (parentCount[i] == 0) {
                if (root == -1) {
                    // If there is no previous candidate root, set the current node as the root.
                    root = i;
                } else {
                    // If we already have a candidate root, return false (multiple roots).
                    return false;
                }
            }
        }

        // If there is no root, return false (no valid tree).
        if (root == -1) {
            return false;
        }

        // Perform a depth-first search (DFS) from the root and check if all nodes are visited.
        return dfs(leftChild, rightChild, root) == n;
    }
};
