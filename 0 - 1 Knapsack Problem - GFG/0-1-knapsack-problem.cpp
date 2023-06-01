//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // recursion
    int solve(int W, int wt[], int val[], int n,int ind){
        if(W == 0 || ind >= n){
            return 0;
        }
        int incl = 0;
        if(W >= wt[ind])
            incl = val[ind] + solve(W-wt[ind] , wt,val,n,ind+1);
        
        int exc = 0 + solve(W,wt,val,n,ind+1);
        
        return max(incl,exc);
    }
    // recursion + memo
    int solvemeo(int W, int wt[], int val[], int n,int ind,vector<vector<int>>&dp){
        if(W == 0 || ind >= n){
            return 0;
        }
        
        if(dp[ind][W] != -1)return dp[ind][W];
        int incl = 0;
        if(W >= wt[ind])
            incl = val[ind] + solvemeo(W-wt[ind] , wt,val,n,ind+1,dp);
        
        int exc = 0 + solvemeo(W,wt,val,n,ind+1,dp);
        
        return dp[ind][W] = max(incl,exc);
        
    }
     int solvebu(int W, int wt[], int val[], int n,int ind){
        vector<vector<int>>dp(n+1,vector<int>(W+1,0));
        
        for(int ind = n-1;ind>=0;ind--){
            for(int c = 0 ;c<= W;c++){
                int incl = 0;
                if(c >= wt[ind])
                    incl = val[ind] + dp[ind+1][c-wt[ind]];
        
                int exc = 0 + dp[ind+1][c];
        
                dp[ind][c] = max(incl,exc);
            }
        }
        return dp[0][W];
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int ind = 0;
        vector<vector<int>>dp(n+1,vector<int>(W+1,-1));
        return solvebu(W,wt,val,n,ind);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends