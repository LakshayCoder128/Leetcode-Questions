class Solution {
public:
    int solve(string& s, int s_ind, string& t, int t_ind, vector<vector<int>>& dp) {
        // If we have matched the entire string 't', return 1 (found a valid subsequence).
        if (t_ind == t.length()) {
            return 1;
        }
        
        // If we have reached the end of 's' but 't' is not yet matched completely, return 0.
        if (s_ind == s.length()) {
            return 0;
        }
        
        // If we have already calculated this subproblem, return the cached result.
        if (dp[s_ind][t_ind] != -1) {
            return dp[s_ind][t_ind];
        }
        
        int take = 0, notTake = 0;
        
        // If the current character in 's' matches the current character in 't', we have two choices:
        // 1. Take the character and move to the next character in both 's' and 't'.
        // 2. Don't take the character and move to the next character in 's' only.
        if (s[s_ind] == t[t_ind]) {
            take = solve(s, s_ind + 1, t, t_ind + 1, dp);
        }
        
        // In any case, we can choose not to take the current character in 's' and move to the next.
        notTake = solve(s, s_ind + 1, t, t_ind, dp);
        
        // Cache the result for this subproblem and return the sum of taking and not taking the character.
        dp[s_ind][t_ind] = take + notTake;
        
        return dp[s_ind][t_ind];
    }

    int numDistinct(string s, string t) {
        int s_len = s.length();
        int t_len = t.length();
        
        vector<vector<int>> dp(s_len, vector<int>(t_len, -1));
        
        return solve(s, 0, t, 0, dp);
    }
};
