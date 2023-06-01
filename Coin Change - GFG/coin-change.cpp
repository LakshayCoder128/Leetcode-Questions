//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
//   long long int Recsolve(int coins[],int N,int sum,int ind){
//       if(sum == 0)return 1;
//       if(sum < 0 || ind >= N) return 0;
//       // exclsion 
//       long long int exc = Recsolve(coins,N,sum,ind+1);
//       // inclusion 
//       long long int inc = Recsolve(coins,N,sum - coins[ind],ind);
      
//       return inc + exc;
//   }
  
  long long int RecMemosolve(int coins[],int N,int sum,int ind,vector<vector<long long int>>&dp){
      if(sum == 0)return 1;
      if(sum < 0 || ind >= N) return 0;
      if(dp[ind][sum] != -1)return dp[ind][sum];
      // exclsion 
      long long int exc = RecMemosolve(coins,N,sum,ind+1,dp);
      // inclusion 
      long long int inc = RecMemosolve(coins,N,sum - coins[ind],ind,dp);
      
      return dp[ind][sum] = inc + exc;
  }
  long long int Tabsolve(int coins[],int N,int S){
      
      vector<vector<long long int>>dp(N+1,vector<long long int>(S+1,0));
      
      for(int i=0;i<N;i++){
          dp[i][0] = 1;
      }
      
      for(int ind =0 ; ind < N ;ind++){
          for(int sum = 1 ; sum <= S;sum++){
                long long int exc = (ind >= 1 ) ? dp[ind-1][sum] : 0;
                long long int inc = (sum - coins[ind] >= 0) ? dp[ind][sum - coins[ind]] : 0;
                dp[ind][sum] = inc + exc;
          }
      }
      return dp[N-1][S];
  }
  
    long long int count(int coins[], int N, int sum) {
        int ind = 0;
        vector<vector<long long int>>dp(N+1,vector<long long int>(sum+1,-1));
        // int ans = Recsolve(coins,N,sum,ind);
        long long int ans = Tabsolve(coins,N,sum);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends