class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        set<pair<int, int>> road_set;
        
        for (auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
            road_set.insert({road[0], road[1]});
            road_set.insert({road[1], road[0]});
        }

        int max_rank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                int rank = degree[i] + degree[j];
                if (road_set.find({i, j}) != road_set.end()) {
                    rank--;
                }
                max_rank = max(max_rank, rank);
            }
        }

        return max_rank;
    }
};

/*
0 - > 1 , 3
1 - > 0 , 2 , 3
2 -> 1
3 -> 0,1


0,1 -> 3 
0,3 -> 4
1,2 - > 3
1.3 - > 4
2,3 -> 5

*/