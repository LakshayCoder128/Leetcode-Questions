class Solution
{
    public:

        int solve(vector<int> &coins, int amount, int ind, vector<vector< int>> &dp)
        {
            if (amount == 0) return dp[amount][ind] = 0;
            if (ind >= coins.size()) return dp[amount][ind] = INT_MAX - 1;
            if (dp[amount][ind] != -1) return dp[amount][ind];
            int res = INT_MAX - 1;
            if (amount - coins[ind] < 0)
            {
                int notChosen = 0 + solve(coins, amount, ind + 1, dp);
                res = notChosen;
            }
            else
            {
                int chosen = 1 + solve(coins, amount - coins[ind], ind, dp);
                int notChosen = 0 + solve(coins, amount, ind + 1, dp);
                res = min(notChosen, chosen);
            }

            return dp[amount][ind] = res;
        }
    int Tab(vector<int> coins, int amt)
    {
        vector<vector < int>> dp(amt + 1, vector<int> (coins.size() + 1, INT_MAX-1 ));

        for (int amount = 0; amount <= amt; amount++)
        {
            for (int ind = coins.size() - 1; ind >= 0; ind--)
            {
                if (amount == 0) dp[amount][ind] = 0;
                else
                {
                    int res = INT_MAX - 1;
                    if (amount - coins[ind] < 0)
                    {
                        int notChosen = 0 + dp[amount][ind + 1];
                        res = notChosen;
                    }
                    else
                    {
                        int chosen = 1 + dp[amount - coins[ind]][ind];
                        int notChosen = 0 + dp[amount][ind + 1];
                        res = min(notChosen, chosen);
                    }

                    dp[amount][ind] = res;
                    // cout << dp[amount][res] << " ";
                }
            }
            // cout << endl;
        }
        return dp[amt][0];
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int ind = 0;
       	// vector<vector < int>> dp(amount + 1, vector<int> (coins.size() + 1, -1));
        int ans = Tab(coins, amount);
        return ans == INT_MAX - 1 ? -1 : ans;
    }
};