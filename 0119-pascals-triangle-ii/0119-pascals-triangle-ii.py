class Solution:
    def ncr(self, n, r, dp):
        if r == 0 or r == n:
            return 1
        if r == 1 or r == n - 1:
            return n
        if dp[n][r] != -1:
            return dp[n][r]
        dp[n][r] = self.ncr(n - 1, r, dp) + self.ncr(n - 1, r - 1, dp)
        return dp[n][r]

    def getRow(self, rowIndex):
        ans = []
        dp = [[-1] * (rowIndex + 1) for _ in range(rowIndex + 1)]
        for i in range(rowIndex + 1):
            ans.append(self.ncr(rowIndex, i, dp))
        return ans