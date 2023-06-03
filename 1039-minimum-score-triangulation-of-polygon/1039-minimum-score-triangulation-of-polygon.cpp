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
    int tab(vector<int> &v)
    {
        vector<vector < int>> dp(v.size() + 1, vector<int> (v.size() + 1, 0));

        for (int s = v.size() - 1; s >= 0; s--)
        {
            for (int e = s + 2; e < v.size(); e++)
            {
                int mini = INT_MAX;
                for (int i = s + 1; i < e; i++)
                {
                    mini = min(mini, v[s] *v[e] *v[i] + dp[s][i] + dp[i][e]);
                }
                dp[s][e] = mini;
            }
        }
        return dp[0][v.size() - 1];
    }
    int minScoreTriangulation(vector<int> &values)
    {
       	// vector<vector < int>> dp(values.size() + 1, vector<int> (values.size() + 1, -1));
       	// int start = 0, end = values.size() - 1;
       	// return RMsolve(values, start, end, dp);

        return tab(values);
    }
};