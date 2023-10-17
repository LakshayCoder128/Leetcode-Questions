# @param {String} s
# @param {String} t
# @return {Integer}
def num_distinct(s, t)
    m = s.length
    n = t.length

    dp = Array.new(m + 1) { Array.new(n + 1, 0) }

    (0..m).each do |i|
        dp[i][n] = 1
    end

    (m - 1).downto(0) do |s_index|
        (n - 1).downto(0) do |t_index|
            dp[s_index][t_index] = dp[s_index + 1][t_index]

            if s[s_index] == t[t_index]
                dp[s_index][t_index] += dp[s_index + 1][t_index + 1]
            end
        end
    end

    dp[0][0]
end