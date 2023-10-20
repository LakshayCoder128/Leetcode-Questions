class Solution {
public:
    vector<vector<int>>dp ;
    void vi(int n){
        vector<vector<int>>dp1(n+1,vector<int>(2,-1));
        dp = dp1;
    } 
    int solve(vector<int>&p,int ind,bool b,int k){
        if(ind >= p.size() || k <= 0) return 0;
        int ans = 0;
        if(dp[ind][b] != -1)return dp[ind][b];
        if(b){
            return dp[ind][b] = max(-p[ind] + solve(p,ind+1,!b,k),solve(p,ind+1,b,k));
        }
        else {
            return dp[ind][b] = max({p[ind] + solve(p,ind+1,!b,k-1),solve(p,ind+1,b,k)});
        }
        // return max(sell, buy);
    }
    int maxProfit(vector<int>& prices) {
        vi(prices.size());
        return solve(prices,0,1,INT_MAX);
    }
};