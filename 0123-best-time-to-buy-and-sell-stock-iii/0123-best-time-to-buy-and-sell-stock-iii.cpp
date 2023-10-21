class Solution {
public:
    int RecursionWithMemoisation(vector<int> &p, int ind, bool canBuy, int k, vector<vector<vector<int>>> &dp) {
        if (ind >= p.size() || k <= 0) return 0;
        
        if (dp[ind][canBuy][k] != -1) return dp[ind][canBuy][k];
        
        if (canBuy) {
            dp[ind][canBuy][k] = max(-p[ind] + RecursionWithMemoisation(p, ind + 1, !canBuy, k, dp), RecursionWithMemoisation(p, ind + 1, canBuy, k, dp));
        } else {
            dp[ind][canBuy][k] = max({ p[ind] + RecursionWithMemoisation(p, ind + 1, !canBuy, k - 1, dp), RecursionWithMemoisation(p, ind + 1, canBuy, k, dp) });
        }
        
        return dp[ind][canBuy][k];
    }
    
    int maxProfit(vector<int> &prices) {
        int k = 2; // change the value of k as per the question 
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(3,vector<int>(k+1,-1)));
        return RecursionWithMemoisation(prices, 0, true, 2, dp);
    }
};