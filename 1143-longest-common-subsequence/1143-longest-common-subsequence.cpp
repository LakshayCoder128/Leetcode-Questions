class Solution
{
    public:
        int Rsolve(string t1, string t2, int i, int j)
        {
            if (i >= t1.size() || j >= t2.size()) return 0;

           	// match
            if (t1[i] == t2[j]) return 1 + Rsolve(t1, t2, i + 1, j + 1);
           	// nomatch
            else
            {
                int op1 = Rsolve(t1, t2, i + 1, j);
                int op2 = Rsolve(t1, t2, i, j + 1);
                return max(op1, op2);
            }
        }
    int RMemosolve(string &t1, string &t2, int i, int j, vector<vector < int>> &dp)
    {
        if (i >= t1.size() || j >= t2.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
       	// match
        if (t1[i] == t2[j]) return dp[i][j] = 1 + RMemosolve(t1, t2, i + 1, j + 1, dp);
       	// nomatch
        else
        {
            int op1 = RMemosolve(t1, t2, i + 1, j, dp);
            int op2 = RMemosolve(t1, t2, i, j + 1, dp);
            return dp[i][j] = max(op1, op2);
        }
    }

    int tabSolve(string &t1, string &t2)
    {
        vector<vector < int>> dp(t1.size() + 1, vector<int> (t2.size() + 1, 0));
        for (int i = t1.size() - 1; i >= 0; i--)
        {
            for (int j = t2.size() - 1; j >= 0; j--)
            {
                if (t1[i] == t2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else
                {
                    int op1 = dp[i + 1][j];
                    int op2 = dp[i][j + 1];
                    dp[i][j] = max(op1, op2);
                }
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2)
    {
       	// vector<vector < int>> dp(text1.size() + 1, vector<int> (text2.size(), -1));
        return tabSolve(text1, text2);
    }
};