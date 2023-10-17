public class Solution {
    public int NumDistinct(string s, string t) {
        int m = s.Length;
        int n = t.Length;

        int[,] dp = new int[m + 1, n + 1];

        for (int i = 0; i <= m; i++) {
            dp[i, n] = 1;
        }

        for (int sIndex = m - 1; sIndex >= 0; sIndex--) {
            for (int tIndex = n - 1; tIndex >= 0; tIndex--) {
                dp[sIndex, tIndex] = dp[sIndex + 1, tIndex];

                if (s[sIndex] == t[tIndex]) {
                    dp[sIndex, tIndex] += dp[sIndex + 1, tIndex + 1];
                }
            }
        }

        return dp[0, 0];
    }
}