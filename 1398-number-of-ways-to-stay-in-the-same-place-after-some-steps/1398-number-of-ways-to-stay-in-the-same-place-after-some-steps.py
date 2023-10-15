MOD = 10**9 + 7

class Solution:
    def TopDown(self, steps, arrLen, pos, dp):
        if steps == 0 and pos == 0:
            return 1
        if steps == 0 and pos != 0:
            return 0
        if steps < 0 or pos < 0 or pos >= arrLen:
            return 0
        if dp[steps][pos] != -1:
            return dp[steps][pos]
        dp[steps][pos] = ((self.TopDown(steps - 1, arrLen, pos, dp) % MOD  # stay
                + self.TopDown(steps - 1, arrLen, pos + 1, dp) % MOD) % MOD  # right
            + self.TopDown(steps - 1, arrLen

, pos - 1, dp) % MOD) % MOD  # left
        return dp[steps][pos]

    def numWays(self, steps, arrLen):
        dp = [[-1 for _ in range(steps + 2)] for _ in range(steps + 1)]
        return self.TopDown(steps, arrLen, 0, dp)