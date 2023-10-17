class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    int edgeCount = 0;
    vector<int> parentCount(n, 0);

    for (int i = 0; i < n; i++) {
        if (leftChild[i] != -1) {
            parentCount[leftChild[i]]++;

            if (parentCount[leftChild[i]] > 1) return false;
            edgeCount++;
        }

        if (rightChild[i] != -1) {
            parentCount[rightChild[i]]++;

            if (parentCount[rightChild[i]] > 1) return false;
            edgeCount++;
        }
    }

    // The count of edges should be n-1.
    if (edgeCount != n - 1) return false;

    // Parent count should be exactly 1 or 0.
    int root = -1;
    for (int i = 0; i < n; i++) {
        if (parentCount[i] == 0) {
            if (root == -1) root = i;
            else return false;
        }
    }

    // Perform a breadth-first search to check the visited node count.
    queue<int> q;
    q.push(root);

    int visitedCount = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visitedCount++;

        if (leftChild[node] != -1) q.push(leftChild[node]);
        if (rightChild[node] != -1) q.push(rightChild[node]);
    }

    return visitedCount == n;
}
};