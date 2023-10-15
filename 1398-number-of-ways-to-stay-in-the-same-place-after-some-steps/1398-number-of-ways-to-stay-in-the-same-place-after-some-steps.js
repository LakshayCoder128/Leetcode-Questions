var numWays = function (steps, arrLen) {
    const MOD = 10 ** 9 + 7;
    let dp = Array.from({ length: steps + 1 }, () => Array(Math.min(steps, arrLen) + 2).fill(0));
    dp[0][0] = 1;

    for (let step = 1; step <= steps; step++) {
        for (let pos = 0; pos < Math.min(steps, arrLen); pos++) {
            dp[step][pos] = ((dp[step - 1][pos] + dp[step - 1][pos + 1]) % MOD + (pos > 0 ? dp[step - 1][pos - 1] : 0)) % MOD;
        }
    }
    return dp[steps][0];
};