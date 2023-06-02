class Solution {
public:
    int solve(int start,int end){
        if(start >= end) return 0;
        int mini = INT_MAX;
        for(int i=start ;i<=end ;i++){
            mini = min(mini, i + max(solve(start,i-1),solve(i+1,end)));
        }
        return mini;
    }
    int Msolve(int start,int end,vector<vector<int>>&dp){
        if(start >= end) return 0;
        int mini = INT_MAX;
        if(dp[start][end] != -1) return dp[start][end];
        for(int i=start ;i<=end ;i++){
            mini = min(mini, i + max(Msolve(start,i-1,dp),Msolve(i+1,end,dp)));
        }
        return dp[start][end] = mini;
    }
    int getMoneyAmount(int n) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return Msolve(1,n,dp);
    }
};