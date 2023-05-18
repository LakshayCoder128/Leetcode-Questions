class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int ans = 0;
        // for(int i=0;i<prices.size()-1;i++){
        //     for(int j=i+1;j<prices.size();j++){
        //         ans =  max(ans,prices[j]-prices[i]);
        //     }
        // }
        // return ans;
        
        vector<int>dp(prices.size());
        dp[prices.size()-1] = 0;
        int maxi = prices[prices.size()-1];
        int ans = 0;
        for(int i=prices.size()-2;i>=0;i--){
            if(prices[i] >= maxi ){dp[i]=0;maxi = prices[i];}
            else {dp[i] = maxi - prices[i]; ans = max(ans,dp[i]);}
        }
        return ans;
    }
};