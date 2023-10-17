class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
       int count = 0;
       vector<int>parent(n, 0);

       for(int i = 0; i < n; i++) {
            if(leftChild[i] != -1) {
                parent[leftChild[i]]++;

                if(parent[leftChild[i]] > 1) return false;
                count++;
            }

            if(rightChild[i] != -1) {
                parent[rightChild[i]]++;

                if(parent[rightChild[i]] > 1) return false;
                count++;
            }
       }

       // count of edges should be n-1
       if(count != n-1) return false;

        //    parent should be exactly 1 or 0.
        int root = -1;
        for(int i = 0; i< n; i++) {
            if(parent[i] == 0) {
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