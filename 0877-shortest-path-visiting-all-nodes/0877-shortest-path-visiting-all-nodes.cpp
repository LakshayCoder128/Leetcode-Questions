class Solution {
    int getKey(int i, int mask){
        return (i<<12)+mask;
    }

public:
    int shortestPathLength(vector<vector<int>>& graph) {
        //Using breadth first search.
        int N=graph.size(), all = (1<<N)-1, step=0;
        queue<int> q;
        unordered_set<int> seen;
        for(int i=0; i<N; i++){
            int k=getKey(i, 1 << i);
            q.push(k);
            seen.insert(k);
        }
        while(q.size()){
            int cnt = q.size();
            while(cnt--){
                int k = q.front(), u=k>>12, mask=k&((1 << 12) - 1);
                q.pop();
                if(mask==all) return step;
                for(int v: graph[u]){
                    int next = getKey(v, mask | (1<<v));
                    if(seen.count(next)) continue;
                    seen.insert(next);
                    q.push(next);
                }
            }
            ++step;
        }
        return -1;

    }
};