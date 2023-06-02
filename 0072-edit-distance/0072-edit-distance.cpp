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
    int Msolve(string &w1, string &w2, int i, int j,vector<vector<int>>&dp)
        {
            if (i >= w1.length()) return w2.length() - j;
            if (j >= w2.length()) return w1.length() - i;

            if(dp[i][j] != -1)return dp[i][j];
            if (w1[i] == w2[j]) return dp[i][j] = Msolve(w1, w2, i + 1, j + 1,dp);
            else
            {

                int insertion = Msolve(w1, w2, i, j + 1,dp);
                int deletion = Msolve(w1, w2, i + 1, j,dp);
                int subs = Msolve(w1, w2, i + 1, j + 1,dp);

                return dp[i][j] = min({ insertion,
                    deletion,
                    subs }) + 1;
            }
        }
    
    int minDistance(string word1, string word2)
    {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return Msolve(word1, word2, 0, 0,dp);
    }
};