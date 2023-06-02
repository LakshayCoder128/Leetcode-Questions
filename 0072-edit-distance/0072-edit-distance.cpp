class Solution
{
    public:
        int solve(string w1, string w2, int i, int j)
        {
            if (i >= w1.length()) return w2.length() - j;
            if (j >= w2.length()) return w1.length() - i;

            if (w1[i] == w2[j]) return solve(w1, w2, i + 1, j + 1);
            else
            {

                int insertion = solve(w1, w2, i, j + 1);
                int deletion = solve(w1, w2, i + 1, j);
                int subs = solve(w1, w2, i + 1, j + 1);

                return min({ insertion,
                    deletion,
                    subs }) + 1;
            }
        }
    int Msolve(string &w1, string &w2, int i, int j, vector<vector < int>> &dp)
    {
        if (i >= w1.length()) return w2.length() - j;
        if (j >= w2.length()) return w1.length() - i;

        if (dp[i][j] != -1) return dp[i][j];
        if (w1[i] == w2[j]) return dp[i][j] = Msolve(w1, w2, i + 1, j + 1, dp);
        else
        {

            int insertion = Msolve(w1, w2, i, j + 1, dp);
            int deletion = Msolve(w1, w2, i + 1, j, dp);
            int subs = Msolve(w1, w2, i + 1, j + 1, dp);

            return dp[i][j] = min({ insertion,
                deletion,
                subs }) + 1;
        }
    }
    int TabS(string &w1, string &w2)
    {
        vector<vector < int>> dp(w1.size() + 1, vector<int> (w2.size() + 1, 0));
        for (int i = 0; i < w1.length(); i++)
        {
            dp[i][w2.length()] = w1.length() - i;
        }
        for (int j = 0; j < w2.length(); j++)
        {
            dp[w1.length()][j] = w2.length() - j;
        }

        for (int i = w1.length() - 1; i >= 0; i--)
        {
            for (int j = w2.length() - 1; j >= 0; j--)
            {
                if (w1[i] == w2[j]) dp[i][j] = dp[i + 1][j + 1];
                else
                {

                    int insertion = dp[i][j + 1];
                    int deletion = dp[i + 1][j];
                    int subs = dp[i + 1][j + 1];

                    dp[i][j] = min({ insertion,
                        deletion,
                        subs }) + 1;
                }
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2)
    {
        vector<vector < int>> dp(word1.size() + 1, vector<int> (word2.size() + 1, -1));
        return TabS(word1, word2);
    }
};