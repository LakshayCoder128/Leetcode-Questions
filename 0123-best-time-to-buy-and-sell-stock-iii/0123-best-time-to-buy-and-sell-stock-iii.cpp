class Solution {
public:
    int bottomup(int K, vector<int> &p) {
        vector<vector<vector<int>>> dp(p.size() + 1, vector<vector<int>>(3, vector<int>(K + 1, 0)));
        
        for (int ind = p.size() - 1; ind >= 0; ind--) {
            for (int b = 0; b <= 1; b++) {
                for (int k = 1; k <= K;

 k++) {
                    if (b) {
                        dp[ind][b][k] = max(-p[ind] + dp[ind + 1][!b][k], dp[ind + 1][b][k]);
                    } else {
                        dp[ind][b][k] = max(p[ind] + dp[ind + 1][!b][k - 1], dp[ind + 1][b][k]);
                    }
                }
            }
        }
        return dp[0][1][K];
    }

    int maxProfit( vector<int> &prices) {
        return bottomup(2, prices);
    }
};