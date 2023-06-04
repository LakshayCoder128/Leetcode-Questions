class Solution
{
    public:
        int solve(int n, vector<int> &dp)
        {
            if (n == 0) return 0;
            if (n < 0) return INT_MAX - 2;
            if (dp[n] != -1) return dp[n];
            int ans = INT_MAX - 2;

            for (int i = 1; i * i <= n; i++)
            {
                ans = min(ans, 1 + solve(n - i *i, dp));
            }

            return dp[n] = ans;
        }
    int numSquares(int N)
    {
        vector<int> dp(N + 1,0);
        // int a = solve(n, Dp);
        
        for(int n=1;n<=N;n++){
             int ans = INT_MAX - 2;

            for (int i = 1; i * i <= n; i++)
            {
                if(n-i*i >= 0)
                    ans = min(ans, 1 + dp[n - i *i]);
                
            }

            dp[n] = ans;
        }
        
        return dp[N];
    }
};