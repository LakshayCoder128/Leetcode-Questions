class Solution
{
    public:
        vector<vector<vector< int>>> dp;

    int solve(vector<int> &p, int ind, bool b, int k)
    {
        if (ind >= p.size() || k <= 0) return 0;

        if (dp[ind][b][k] != -1) return dp[ind][b][k];
        if (b)
        {
            return dp[ind][b][k] = max(-p[ind] + solve(p, ind + 1, !b, k), solve(p, ind + 1, b, k));
        }
        else
        {
            return dp[ind][b][k] = max({ p[ind] + solve(p, ind + 1, !b, k - 1),
                solve(p, ind + 1, b, k) });
        }
       	// return max(sell, buy);
    }

    int bottomup(int K, vector<int> &p)
    {
        vector<vector<vector< int>>> dp(p.size() + 1, vector<vector < int>> (3, vector<int> (K + 1, 0)));

        for (int ind = p.size()-1; ind >= 0; ind--)
        {
            for (int b = 0; b <=1 ; b++)
            {
                for (int k = 1; k <= K; k++)
                {
                    if (b)
                    {
                        dp[ind][b][k] = max(-p[ind] + dp[ind + 1][!b][k], dp[ind + 1][b][k]);
                    }
                    else
                    {
                        dp[ind][b][k] = max(p[ind] + dp[ind + 1][!b][k - 1],
                            dp[ind + 1][b][k]);
                    }
                }
            }
        }
        return dp[0][1][K];
    }

    int maxProfit(int k, vector<int> &prices)
    {
       	// dp.resize(prices.size() + 1, vector<vector < int>> (3, vector<int> (k + 1, -1)));
       	// return solve(prices, 0, 1, k);
        return bottomup(k, prices);
    }
};