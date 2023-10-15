public class Solution {
    private static final int MOD = 1000000007;

    public int numWays(int steps, int arrLen) {
        int[][] dp = new int[steps + 1][Math.min(steps, arrLen) + 2];
        dp[0][0] = 1;

        for (int step = 1; step <= steps; step++) {
            for (int pos = 0; pos < Math.min(steps, arrLen); pos++) {
                dp[step][pos] = (((dp[step - 1][pos] % MOD)  // stay
                        + (dp[step - 1][pos + 1] % MOD)) % MOD  // right
                        + ((pos > 0) ? (dp[step - 1][pos - 1] % MOD) : 0)) % MOD;  // left
            }
        }
        return dp[steps][0];
    }
}