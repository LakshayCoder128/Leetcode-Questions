class Solution {
public:
    int ncr(int n,int r,vector<vector<int>>&dp){
        if(r ==0 || r == n) return 1;
        if(r == 1 || r== n-1 ) return n;
        if(dp[n][r] != -1)return dp[n][r];
        return dp[n][r] = ncr(n-1,r,dp) + ncr(n-1,r-1,dp) ;
        
    }
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        vector<vector<int>>dp(rowIndex+1,vector<int>(rowIndex+1,-1));
        for(int i=0;i<=rowIndex;i++){
            ans.push_back(ncr(rowIndex,i,dp));
        }
        return ans;
    }
};