class Solution
{
    public:
        
    int dp[46];
    
    int solve(int s,int n){
        if(s==n)return 1;
        if(s> n) return 0;
        
        if(dp[s]!= -1 ) return dp[s];
        int ans = solve(s+1,n) + solve(s+2,n);
        return dp[s] = ans;
    }
        int climbStairs(int n)
        {
           	// long long a = 1, b = 1;
           	// while (n--)
           	//     a = (b += a) - a;
           	// return (int)a;

           	// Dp
           	//             if(n==1 || n==2) return n; 
           	//             vector<int>dp(n+1);
           	//            	// 0 1 2 3 4
           	//            	// 5 3 2 1 1
           	//             dp[n] = 1;dp[n-1] = 1;
           	//             for(int i=n-2;i>=0;i--){
           	//                 dp[i] = dp[i+1]+dp[i+2];
           	//                	// cout<<i<<" "<<dp[i]<<" "<<endl;
           	//             }

           	//             return dp[0];

            // int one = 1, two = 1;
            // for (int i = 0; i < n - 1; i++)
            // {
            //     int temp = one;
            //     one = one + two;
            //     two = temp;
            // }
            // return one;
            
            for(int i=0;i<46;i++)dp[i]=-1;
            return solve(0,n);
            
        }
   	// 2 1 
};