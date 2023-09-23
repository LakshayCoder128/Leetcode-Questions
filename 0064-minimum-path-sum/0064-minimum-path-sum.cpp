class Solution {
public:
    int solve(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i < 0 || j<0)return INT_MAX;
        else if(i == 0 && j==0)return dp[i][j] = grid[i][j];
        if(dp[i][j] != -1)return dp[i][j];
        return dp[i][j] = grid[i][j] + min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int i=grid.size(),j=grid[0].size();
        vector<vector<int>>dp(i+1,vector<int>(j+1,-1));
        return solve(i-1,j-1,grid,dp);
    }
};