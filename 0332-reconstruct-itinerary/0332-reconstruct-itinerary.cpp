class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, priority_queue<string, vector<string>, greater<string>> > graph;
        for(auto ticket : tickets){
            graph[ticket[0]].push(ticket[1]);
        } 

        vector<string> ans = {};

        function<void(const string&)> dfs = [&](const string& now){
            while(!graph[now].empty()){
                string tmp = graph[now].top();
                graph[now].pop();
                dfs(tmp);
            }
            ans.push_back(now);
        };

        string now = "JFK";
        dfs(now);
        reverse(ans.begin(), ans.end());

        // 
        return ans;
    }
};