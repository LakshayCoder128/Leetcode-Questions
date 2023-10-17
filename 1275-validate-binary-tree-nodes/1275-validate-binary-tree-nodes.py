from collections import deque

class Solution:
    def validateBinaryTreeNodes(self, n, leftChild, rightChild):
        edgeCount = 0
        parentCount = [0] * n

        for i in range(n):
            if leftChild[i] != -1:
                parentCount[leftChild[i]] += 1

                if parentCount[leftChild[i]] > 1:
                    return False
                edgeCount += 1

            if rightChild[i] != -1:
                parentCount[rightChild[i]] += 1

                if parentCount[rightChild[i]] > 1:
                    return False
                edgeCount += 1

        if edgeCount != n - 1:
            return False

        root = -1
        for i in range(n):
            if parentCount[i] == 0:
                if root == -1:
                    root = i
                else:
                    return False

        q = deque()
        q.append(root)

        visitedCount = 0

        while q:
            node = q.popleft()
            visitedCount += 1

            if leftChild[node] != -1:
                q.append(leftChild[node])
            if rightChild[node] != -1:
                q.append(rightChild[node])

        return visitedCount == n