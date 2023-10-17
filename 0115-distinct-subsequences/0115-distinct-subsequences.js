var numDistinct = function (s, t) {
    const dp = Array(s.length)
        .fill(0)
        .map(() => Array(t.length).fill(-1));

    function recursiveWithMemoization(s_ind, t_ind) {
        if (t_ind === t.length) {
            return 1;
        }
        if (s_ind === s.length) {
            return 0;
        }

        if (dp[s_ind][t_ind] !== -1) {
            return dp[s_ind][t_ind];
        }

        let take = 0, notTake = 0;

        if (s[s_ind] === t[t_ind]) {
            take = recursiveWithMemoization(s_ind + 1, t_ind + 1);
        }

        notTake = recursiveWithMemoization(s_ind + 1, t_ind);

        dp[s_ind][t_ind] = take + notTake;

        return dp[s_ind][t_ind];
    }

    return recursiveWithMemoization(0, 0);
};