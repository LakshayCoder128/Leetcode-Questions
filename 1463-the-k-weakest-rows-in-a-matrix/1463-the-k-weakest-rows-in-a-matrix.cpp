class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>> , greater<pair<int,int>> >pq;
        int cnt = 0;
        
        for(auto const &i :mat){
           int s = accumulate(i.begin(),i.end(),0);
           pq.push({s,cnt++});    
        }

        while(ans.size()<k && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};