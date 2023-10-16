
    def ncr(n, r, dp)
        return 1 if r == 0 || r == n
        return n if r == 1 || r == n - 1
        return dp[n][r] if dp[n][r] != -1

        dp[n][r] = ncr(n - 1, r, dp) + ncr(n - 1, r - 1, dp)
        dp[n][r]
    end

    def get_row(row_index)
        ans = []
        dp = Array.new(row_index + 1) { Array.new(row_index + 1, -1) }
        (0..row_index).each do |i|
            ans << ncr(row_index, i, dp)
        end
        ans
    end
