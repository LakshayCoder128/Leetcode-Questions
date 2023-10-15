static int MOD = 1e9 + 7;

class Solution {
public:
    int TopDown(int steps, int arrLen, int pos, vector<vector<int>>& dp) {
        if (steps == 0 && pos == 0) return 1;
        if (steps == 0 && pos != 0) return 0;
        if (steps < 0 || pos < 0 || pos >= arrLen) return 0;
        if (dp[steps][pos] != -1) return dp[steps][pos];
        return dp[steps][pos] = ((TopDown(steps - 1, arrLen, pos, dp) % MOD  // stay
                + TopDown(steps - 1, arrLen, pos + 1, dp) % MOD) % MOD  // right
            + TopDown(steps - 1, arrLen, pos - 1, dp) % MOD) % MOD;  // left
    }

    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(steps+2, -1));
        return TopDown(steps, arrLen, 0, dp);
    }
};