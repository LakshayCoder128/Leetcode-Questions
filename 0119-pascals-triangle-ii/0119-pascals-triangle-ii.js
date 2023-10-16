
    var ncr= function(n, r, dp) {
        if (r === 0 || r === n) return 1;
        if (r === 1 || r === n - 1) return n;
        if (dp[n][r] !== -1) return dp[n][r];
        dp[n][r] =  ncr(n - 1, r, dp) +  ncr(n - 1, r - 1, dp);
        return dp[n][r];
    }

    var getRow = function(rowIndex) {
        const ans = [];
        const dp = new Array(rowIndex + 1).fill(-1).map(() => new Array(rowIndex + 1).fill(-1));
        for (let i = 0; i <= rowIndex; i++) {
            ans.push( ncr(rowIndex, i, dp));
        }
        return ans;
    }