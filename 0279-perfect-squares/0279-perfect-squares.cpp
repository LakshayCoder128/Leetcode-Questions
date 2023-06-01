class Solution {
public:
    // recursive 
    int solve(int num, int n){
        if(n == 0)return 0;
        if(n - num * num < 0) return INT_MAX-1;
        
        // exclu 
        int exc = solve(num+1,n);
        // incl
        int incl = 1 + solve(num,n-num*num);
        
        return min(exc,incl);
    }
    
    // recursion  + memo 
    int solvedp(int num, int n,vector<int>&dp){
        if(n == 0)return 0;
        if(n - num * num < 0) return INT_MAX-1;
        if(dp[n] != -1)return dp[n];
        // exclu 
        int exc = solvedp(num+1,n,dp);
        // incl
        int incl = 1 + solvedp(num,n-num*num,dp);
        return dp[n] = min(exc,incl);
    }
    int numSquares(int n) {
        int num = 1;
        vector<int>dp(n+1,-1);
        int ans = solvedp(num,n,dp);
        return ans;
    }
};