class Solution {
    private static final int MOD = 1000000007;

    public int TopDown(int steps, int arrLen, int pos, int[][] dp) {
        if (steps == 0 && pos == 0) return 1;
        if (steps == 0 && pos != 0) return 0;
        if (steps < 0 || pos < 0 || pos >= arrLen) return 0;
        if (dp[steps][pos] != -1) return dp[steps][pos];
        return dp[steps][pos] = ((TopDown(steps - 1, arrLen, pos, dp) % MOD  // stay
                + TopDown(steps - 1, arrLen, pos + 1, dp) % MOD) % MOD  // right
            + TopDown(steps - 1, arrLen, pos - 1, dp) % MOD) % MOD;  // left
    }

    public int numWays(int steps, int arrLen) {
        int[][] dp = new int[steps + 1][steps+2];
        for (int[] row : dp) Arrays.fill(row, -1);
        return TopDown(steps, arrLen, 0, dp);
    }
}