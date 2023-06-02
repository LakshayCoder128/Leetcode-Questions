class Solution
{
    public:
        int solve(int n)
        {
            if (n <= 1) return 1;
            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                ans += solve(i - 1) *solve(n - i);
            }
            return ans;
        }
    int Msolve(int n, vector<int> &dp)
    {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += Msolve(i - 1, dp) *Msolve(n - i, dp);
        }
        return dp[n] = ans;
    }
    int numTrees(int n)
    {
        vector<int> dp(n + 1, -1);
        return Msolve(n, dp);
    }
};