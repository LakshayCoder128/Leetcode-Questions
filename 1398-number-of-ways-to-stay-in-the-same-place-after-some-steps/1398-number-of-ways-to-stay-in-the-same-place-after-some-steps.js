var MOD = 1000000007;

var TopDown = function (steps, arrLen, pos, dp) {
    if (steps === 0 && pos === 0) return 1;
    if (steps === 0 && pos !== 0) return 0;
    if (steps < 0 || pos < 0 || pos >= arrLen) return 0;
    if (dp[steps][pos] !== -1) return dp[steps][pos];
    dp[steps][pos] =
        ((((TopDown(steps - 1, arrLen, pos, dp) % MOD) + // stay
            (TopDown(steps - 1, arrLen, pos + 1, dp) % MOD)) %
            MOD) + // right
            (TopDown(steps - 1, arrLen, pos - 1, dp) % MOD)) %
        MOD; // left
    return dp[steps][pos];
};

var numWays = function (steps, arrLen) {
    const dp = Array.from({ length: steps + 1 }, () => Array(steps+2).fill(-1));
    return TopDown(steps, arrLen, 0, dp);
};
