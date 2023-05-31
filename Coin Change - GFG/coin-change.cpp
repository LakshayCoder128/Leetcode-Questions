//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
    
long long getWays(int n, int c[],int N, int sum, int current, vector<vector<long long>>& dp) {

    if (sum > n)
        return 0;
    if (dp[current][sum] != -1)
        return dp[current][sum];
    if (sum == n) {
        return 1;

    }
    long long count = 0;
    for (int i = current ; i < N ; i++ )
        count += getWays(n, c, N,sum + c[i], i , dp);

    return dp[current][sum] = count;

}
  public:
 
    long long int count(int coins[], int N, int sum) {
        int ind = 0;
        vector<vector<long long>>dp(N,vector<long long>(sum+1,-1));
        return getWays(sum,coins,N,0,ind,dp);
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