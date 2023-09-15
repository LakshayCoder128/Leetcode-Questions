class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0,{points[0][0], points[0][1]}});
        set<pair<int, int>> vis;
        int totalCost=0;
        while(!pq.empty()){
            int cost=-1*pq.top().first;
            int x1=pq.top().second.first;
            int y1=pq.top().second.second;
            pq.pop();
            if(vis.find({x1,y1})!=vis.end()) continue;
            totalCost+=cost;
            vis.insert({x1, y1});
            for(const auto& it: points){
                int x2=it[0];
                int y2=it[1];
                if(vis.find({x2,y2})==vis.end()){
                    int dis=abs(x2-x1)+abs(y2-y1);
                    pq.push({-1*dis, {x2, y2}});
                }
            }
        }
        return totalCost;
    }
};