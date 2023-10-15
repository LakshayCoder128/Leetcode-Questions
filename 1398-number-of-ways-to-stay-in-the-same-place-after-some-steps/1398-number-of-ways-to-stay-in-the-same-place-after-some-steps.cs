public class Solution {
    public int NumWays(int steps, int arrLen) {
        const int MOD = 1000000007;
        long[][] dp = new long[steps + 1][];
        for (int i = 0; i <= steps; i++) {
            dp[i] = new long[Math.Min(steps, arrLen) + 2];
            for (int j = 0; j < Math.Min(steps, arrLen) + 2; j++) {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;

        for (int step = 1; step <= steps; step++) {
            for (int pos = 0; pos < Math.Min(steps, arrLen); pos++) {
                dp[step][pos] = ((dp[step - 1][pos] + dp[step - 1][pos + 1]) % MOD + (pos > 0 ? dp[step - 1][pos - 1] : 0)) % MOD;
            }
        }
        return (int)dp[steps][0];
    }
}