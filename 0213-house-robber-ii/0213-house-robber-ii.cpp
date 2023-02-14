class Solution
{
    public:
        int rob(vector<int> &nums)
        {
            if (nums.size() == 1) return nums[0];
            if (nums.size() == 2) return max(nums[0], nums[1]);
            vector<int> dp(nums.size());
            dp[0] = nums[0];
            dp[1] = nums[1];
            dp[2] = dp[0] + nums[2];

            for (int i = 3; i < nums.size() - 1; i++)
            {
                dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
            }

            int ans1 = max(dp[nums.size() - 2], dp[nums.size() - 3]);

            dp[0] = nums[1];
            dp[1] = nums[2];
            dp[2] = dp[0] + nums[3];

            for (int i = 4; i < nums.size(); i++)
            {
                dp[i - 1] = max(dp[i - 3], dp[i - 4]) + nums[i];
            }

            int ans2 = max(dp[nums.size() - 2], dp[nums.size() - 3]);

            return max(ans1, ans2);
        }
};