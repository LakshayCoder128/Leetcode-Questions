class Solution
{
    public:
       
    int Recursive(vector<int> &p, int ind, bool b, int k)
    {
        if (ind >= p.size() || k <= 0) return 0;
        int ans = 0;
        
        if (b)
        {
            return max(-p[ind] + Recursive(p, ind + 1, !b, k), // bought it 
                        Recursive(p, ind + 1, b, k));   // left it 
        }
        else
        {
            return max({ p[ind] + Recursive(p, ind + 1, !b, k - 1), // sold it 
                Recursive(p, ind + 1, b, k) }); // hold it
        }
       	
    }

    int RecursionWithMemoisation(vector<int> &p, int ind, bool canBuy, int k,vector<vector<int>>&dp)
    {
        if (ind >= p.size() || k <= 0) return 0;
        int ans = 0;
        
        if(dp[ind][canBuy] != -1)return dp[ind][canBuy];
        if (canBuy)
        {
            return dp[ind][canBuy] = max(-p[ind] + RecursionWithMemoisation(p, ind + 1, !canBuy, k,dp), // bought it 
                        RecursionWithMemoisation(p, ind + 1, canBuy, k,dp));   // left it 
        }
        else
        {
            return dp[ind][canBuy] = max({ p[ind] + RecursionWithMemoisation(p, ind + 1, !canBuy, k - 1,dp), // sold it 
                RecursionWithMemoisation(p, ind + 1, canBuy, k,dp) }); // hold it
        }
       	
    }

    int maxProfit(vector<int> &prices)
    {
        // return Recursive(prices, 0, 1, INT_MAX);
        vector<vector<int>> dp(prices.size() + 1, vector<int> (2, -1));
        return RecursionWithMemoisation(prices, 0, 1, INT_MAX,dp);


    }
};