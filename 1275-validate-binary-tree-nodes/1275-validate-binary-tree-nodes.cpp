class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       int count = 0;
       vector<int>indegree(n, 0);

       for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                indegree[leftChild[i]]++;

                if(indegree[leftChild[i]] > 1) return false;
                count++;
            }

            if(rightChild[i] != -1) {
                indegree[rightChild[i]]++;

                if(indegree[rightChild[i]] > 1) return false;
                count++;
            }
       }

       // count of edges should be n-1
       if(count != n-1) return false;

        //    indegree should be exactly 1 or 0.
        int root = -1;
        for(int i = 0; i< n; i++) {
            if(indegree[i] == 0) {
                if(root == -1) root = i;
                else return false;
            };
        }

        // bfs for checking visited node count.
        queue<int>q;
        q.push(root);
        
        count = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            if(leftChild[node] != -1) q.push(leftChild[node]);
            if(rightChild[node] != -1) q.push(rightChild[node]);
        }
        return count == n;

    }
};