/**
 * @param {string} s
 * @param {string} t
 * @return {number}
 */
var numDistinct = function(s, t) {
     const m = s.length;
    const n = t.length;

    const dp = new Array(m + 1).fill().map(() => new Array(n + 1).fill(0));

    for (let i = 0; i <= m; i++) {
        dp[i][n] = 1;
    }

    for (let sIndex = m - 1; sIndex >= 0; sIndex--) {
        for (let tIndex = n - 1; tIndex >= 0; tIndex--) {
            dp[sIndex][tIndex] = dp[sIndex + 1][tIndex];

            if (s[sIndex] === t[tIndex]) {
                dp[sIndex][tIndex] += dp[sIndex + 1][tIndex + 1];
            }
        }
    }

    return dp[0][0];
};