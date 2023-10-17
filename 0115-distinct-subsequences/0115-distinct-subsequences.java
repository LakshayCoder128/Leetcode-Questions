class Solution {
    public int numDistinct(String s, String t) {
        int m = s.length();
        int n = t.length();

        int[][] dp = new int[m + 1][n + 1];

        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }

        for (int sIndex = m - 1; sIndex >= 0; sIndex--) {
            for (int tIndex = n - 1; tIndex >= 0; tIndex--) {
                dp[sIndex][tIndex] = dp[sIndex + 1][tIndex];

                if (s.charAt(sIndex) == t.charAt(tIndex)) {
                    dp[sIndex][tIndex] += dp[sIndex + 1][tIndex + 1];
                }
            }
        }

        return dp[0][0];
    }
}