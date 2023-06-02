//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
public:
    int solve(int n , int r, vector<vector<int>>&dp){
        if(dp[n][r] != -1)return dp[n][r];
        if(r>n)return 0;
        if(r==0 || r == n)return dp[n][r] = 1;
        int ans =  (nCr(n-1,r-1)+ nCr(n-1,r));
        return dp[n][r] = ans;
    }
    int Tab(int n,int r){
        if(r>n)return 0;
        vector<vector<int>>dp(n+1,vector<int>(r+1,1));
        int ans = 0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=min(i,r);j++){
                if(i==j || j==0) dp[i][j] = 1;
                else dp[i][j] = (dp[i-1][j-1]+ dp[i-1][j])%1000000007;
            }
        }
        return dp[n][r];
    }
    int nCr(int n, int r){
        // vector<vector<int>>dp(n+1,vector<int>(r+1,-1));
        int ans = Tab(n,r);
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends