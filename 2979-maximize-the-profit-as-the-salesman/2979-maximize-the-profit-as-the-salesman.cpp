class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>>& offers) {
    int dp[100002] = {};
    unordered_map<int, vector<pair<int, int>>> m;
    for (const auto &offer : offers)
        m[offer[1]].push_back({offer[0], offer[2]});
    for (int k = 0; k < n; ++k) {
        dp[k + 1] = dp[k];
        if (m.count(k))
            for (auto [start, gold] : m[k])
                dp[k + 1] = max(dp[k + 1], dp[start] + gold);
    }
    return dp[n];
}
};