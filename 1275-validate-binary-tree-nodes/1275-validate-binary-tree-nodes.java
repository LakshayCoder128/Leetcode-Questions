class Solution {
    public boolean validateBinaryTreeNodes(int n, int[] leftChild, int[] rightChild) {
    int edgeCount = 0;
    int[] parentCount = new int[n];

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

    if (edgeCount != n - 1) return false;

    int root = -1;
    for (int i = 0; i < n; i++) {
        if (parentCount[i] == 0) {
            if (root == -1) root = i;
            else return false;
        }
    }

    Queue<Integer> q = new LinkedList<>();
    q.add(root);

    int visitedCount = 0;

    while (!q.isEmpty()) {
        int node = q.poll();
        visitedCount++;

        if (leftChild[node] != -1) q.add(leftChild[node]);
        if (rightChild[node] != -1) q.add(rightChild[node]);
    }

    return visitedCount == n;
}
}