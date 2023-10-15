public class Solution {
    private const int MOD = 1000000007;

    public int TopDown(int steps, int arrLen, int pos, int[][] dp) {
        if (steps == 0 && pos == 0) return 1;
        if (steps == 0 && pos != 0) return 0;
        if (steps < 0 || pos < 0 || pos >= arrLen) return 0;
        if (dp[steps][pos] != -1) return dp[steps][pos];
        dp[steps][pos] = ((TopDown(steps - 1, arrLen, pos, dp) % MOD  // stay
            + TopDown(steps - 1, arrLen, pos + 1, dp) % MOD) % MOD  // right
            + TopDown(steps - 1, arrLen, pos - 1, dp) % MOD) % MOD;  // left
        return dp[steps][pos];
    }

    public int NumWays(int steps, int arrLen) {
        int[][] dp = new int[steps + 1][];
        for (int i = 0; i <= steps; i++) {
            dp[i] = new int[steps + 2]; 
            for (int j = 0; j < steps + 2; j++) {
                dp[i][j] = -1;
            }
        }
        return TopDown(steps, arrLen, 0, dp);
    }
}
