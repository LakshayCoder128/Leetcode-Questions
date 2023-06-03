class Solution
{
    public:
        int Rsolve(vector<int> &v, int s, int e)
        {
            if (s + 1 == e) return 0;	// straight line base case
            int mini = INT_MAX;
            for (int i = s + 1; i < e; i++)
            {
               	// cal mini = min of (mini, current triangle + rest part of the figure)
                mini = min(mini, v[s] *v[e] *v[i] + Rsolve(v, s, i) + Rsolve(v, i, e));
            }
            return mini;
        }
    int RMsolve(vector<int> &v, int s, int e, vector<vector< int>> &dp)
    {
        if (s + 1 == e) return 0;	// straight line base case
        int mini = INT_MAX;
        if (dp[s][e] != -1) return dp[s][e];
        for (int i = s + 1; i < e; i++)
        {
           	// cal mini = min of (mini, current triangle + rest part of the figure)
            mini = min(mini, v[s] *v[e] *v[i] + RMsolve(v, s, i, dp) + RMsolve(v, i, e, dp));
        }
        return dp[s][e] = mini;
    }
    int minScoreTriangulation(vector<int> &values)
    {
        vector<vector < int>> dp(values.size() + 1, vector<int> (values.size() + 1, -1));
        int start = 0, end = values.size() - 1;
        return RMsolve(values, start, end, dp);
    }
};