class Solution
{
    public:
        int solve(vector<int> &days, vector<int> &costs, int ind, vector< int > &dp)
        {
            if (ind >= days.size()) return 0;
            if (dp[ind] != -1) return dp[ind];
            int op1 = costs[0] + solve(days, costs, ind + 1, dp);

            int i;
            for (i = ind; i < days.size() && days[i] < days[ind] + 7; i++) {}
            int op2 = costs[1] + solve(days, costs, i, dp);

            for (i = ind; i < days.size() && days[i] < days[ind] + 30; i++) {}

            int op3 = costs[2] + solve(days, costs, i, dp);

            return dp[ind] = min(op1, min(op2, op3));
        }
    
    
    int mincostTickets(vector<int> &days, vector<int> &costs)
    {
        // vector<int> dp(days.size() + 1, -1);
        // int ans = solve(days, costs, 0, dp);
        
        // return ans;
        
        vector<int> dp(days.size() + 1, 0);
        for(int ind = days.size()-1;ind >=0;ind--){
            int op1 = costs[0] + dp[ind + 1];

            int i;
            for (i = ind; i < days.size() && days[i] < days[ind] + 7; i++) {}
            int op2 = costs[1] + dp[i];

            for (i = ind; i < days.size() && days[i] < days[ind] + 30; i++) {}

            int op3 = costs[2] + dp[i];

            dp[ind] = min(op1, min(op2, op3));
        }
        return dp[0];
    }
};