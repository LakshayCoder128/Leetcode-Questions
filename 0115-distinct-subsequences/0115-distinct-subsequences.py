class Solution:
    def numDistinct(self, s: str, t: str) -> int:
        m, n = len(s), len(t)
        dp = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m + 1):
            dp[i][n] = 1

        for sIndex in range(m - 1, -1, -1):
            for tIndex in range(n - 1, -1, -1):
                dp[sIndex][tIndex] = dp[sIndex + 1][tIndex]

                if s[sIndex] == t[tIndex]:
                    dp[sIndex][tIndex] += dp[sIndex + 1][tIndex + 1]

        return dp[0][0]