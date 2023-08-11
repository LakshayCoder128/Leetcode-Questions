class Solution
{
    public:
        int solve(int amount, vector<int> &coins, int ind, vector<vector< int>> &dp)
        {
            if (amount < 0) return 0;
            if (amount == 0) return 1;
            if (dp[amount][ind] != -1) return dp[amount][ind];
            int ways = 0;
            for (int i = ind; i < coins.size(); i++)
            {
                ways += solve(amount - coins[i], coins, i, dp);
            }
            return dp[amount][ind] = ways;
        }

    int change(int amount, vector<int> &coins)
    {
        int index = 0;
        vector<vector < int>> dp(amount + 1, vector<int> (coins.size() + 1, 0));
       	// return solve(amount, coins, index, dp);

        for (int ind = 0; ind <= coins.size(); ind++)
        {
            dp[0][ind] = 1;
        }
        for (int amt = 1; amt <= amount; amt++)
        {
            for (int ind = coins.size() - 1; ind >= 0; ind--)
            {
                int ways = 0;
                for (int i = ind; i < coins.size(); i++)
                {
                    if(amt - coins[i] >= 0)
                    ways += dp[amt - coins[i]][i];
                }
                dp[amt][ind] = ways;
            }
        }
        return dp[amount][0];
    }
};