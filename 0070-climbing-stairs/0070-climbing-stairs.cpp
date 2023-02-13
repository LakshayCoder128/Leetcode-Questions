class Solution
{
    public:
        int climbStairs(int n)
        {
            // long long a = 1, b = 1;
            // while (n--)
            //     a = (b += a) - a;
            // return (int)a;
            
            // Dp
            if(n==1 || n==2) return n; 
            vector<int>dp(n+1);
            // 0 1 2 3 4
            // 5 3 2 1 1
            dp[n] = 1;dp[n-1] = 1;
            for(int i=n-2;i>=0;i--){
                dp[i] = dp[i+1]+dp[i+2];
                // cout<<i<<" "<<dp[i]<<" "<<endl;
            }
            
            return dp[0];
        }
};