class Solution {
public:
    int coinsU = INT_MAX;
    int solve(vector<int>& coins, int amount,int ind,vector<vector<int>>&dp){
        if(amount == 0 ) return dp[amount][ind] = 0;
        if(ind >= coins.size()) return dp[amount][ind] = INT_MAX -1;
        if(dp[amount][ind]!= -1) return dp[amount][ind];
        int res = INT_MAX-1;
        if(amount - coins[ind] < 0 )
        {
            int notChosen = 0 + solve(coins,amount,ind+1,dp);
            res = notChosen;
        }
        else {
            int chosen = 1+solve(coins,amount-coins[ind],ind,dp);
            int notChosen = 0 + solve(coins,amount,ind+1,dp);
            res = min (notChosen,chosen);
        }
        
        return dp[amount][ind] = res;
    }
    int coinChange(vector<int>& coins, int amount) {
        int ind = 0;
        vector<vector<int>>dp(amount+1,vector<int>(coins.size()+1,-1));
        int ans = solve(coins,amount,ind,dp);
        return  dp[amount][ind] == INT_MAX-1 ? -1 : dp[amount][ind];
    }
};