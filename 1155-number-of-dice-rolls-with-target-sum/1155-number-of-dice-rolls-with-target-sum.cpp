class Solution
{
    public:
        int mod = 1e9 + 7;
    int dp[1004][32];
    int helper(int n, int &k, int target)
    {
        if (n == 0 && target == 0)
            return 1;
        if (target <= 0 || n <= 0)
            return 0;
        if (dp[target][n] != -1)
            return dp[target][n];
        long long ans = 0;
        for (int i = 1; i <= k; i++)
        {
            ans = (ans + helper(n - 1, k, target - i)) % mod;
        }
        dp[target][n] = ans;
        return ans;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        memset(dp, -1, sizeof(dp));
        return helper(n, k, target);
    }
};