class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        vector<int>ans;
        for(auto i:nums){
            m[i]++;
        }

        priority_queue<pair<int,int>>pq;
        for(auto i:m){
            pq.push({i.second,i.first});
        }

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};