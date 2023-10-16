public class Solution {
    public int Ncr(int n, int r, int[][] dp) {
        if (r == 0 || r == n) return 1;
        if (r == 1 || r == n - 1) return n;
        if (dp[n][r] != -1) return dp[n][r];
        dp[n][r] = Ncr(n - 1, r, dp) + Ncr(n - 1, r - 1, dp);
        return dp[n][r];
    }

    public int[] GetRow(int rowIndex) {
        int[] ans = new int[rowIndex + 1];
        int[][] dp = new int[rowIndex + 1][];
        for (int i = 0; i <= rowIndex; i++) {
            dp[i] = new int[rowIndex + 1];
            for (int j = 0; j <= rowIndex; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i <= rowIndex; i++) {
            ans[i] = Ncr(rowIndex, i, dp);
        }
        return ans;
    }
}