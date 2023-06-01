class Solution
{
    public:
       	// recursive 
        int solve(int num, int n)
        {
            if (n == 0) return 0;
            if (n - num * num < 0) return INT_MAX - 1;

           	// exclu 
            int exc = solve(num + 1, n);
           	// incl
            int incl = 1 + solve(num, n - num *num);

            return min(exc, incl);
        }

   	// recursion  + memo 
    int solvedp(int num, int n, vector<int> &dp)
    {
        if (n == 0) return 0;
        if (n - num * num < 0) return INT_MAX - 1;
        if (dp[n] != -1) return dp[n];
       	// exclu 
        int exc = solvedp(num + 1, n, dp);
       	// incl
        int incl = 1 + solvedp(num, n - num *num, dp);
        return dp[n] = min(exc, incl);
    }
   	// bottomup
    int solveBu(int N)
    {
        vector<int> dp(N + 1, 0);

        for (int n = 1; n <= N; n++)
        {

            int ans = INT_MAX;

            for (int i = 1; i*i <= n; i++)
            {
                ans = min(ans, 1 + dp[n - i *i]);
            }
            dp[n] = ans;
        }
        return dp[N];
    }
    int numSquares(int n)
    {
        int num = 1;
        vector<int> dp(n + 1, -1);
        int ans = solveBu(n);
        return ans;
    }
};