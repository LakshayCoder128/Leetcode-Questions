MOD = 10**9 + 7

class Solution:
    def numWays(self, steps: int, arrLen: int) -> int:
        dp = [[0] * (min(steps, arrLen) + 2) for _ in range(steps + 1)]
        dp[0][0] = 1

        for step in range(1, steps + 1):
            for pos in range(min(steps, arrLen)):
                dp[step][pos] = ((dp[step - 1][pos] + dp[step - 1][pos + 1]) % MOD + (dp[step - 1][pos - 1] if pos > 0 else 0)) % MOD

        return dp[steps][0]