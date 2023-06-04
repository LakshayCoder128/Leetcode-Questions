class Solution
{
    public:
        int Dsolve(vector<int> &nums, int target, vector<int> &dp)
        {
            if (target < 0) return 0;
            if (target == 0) return 1;
            if (dp[target] != -1) return dp[target];
            int ways = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                ways += Dsolve(nums, target - nums[i], dp);
            }
            return dp[target] = ways;
        }
    int tabsolve(vector<int> &nums, int T)
    {
        vector < unsigned int > dp(T + 1, 1);
        for (int target = 1; target <= T; target++)
        {
            int ways = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                ways += target - nums[i] >= 0 ? dp[target - nums[i]] : 0;
            }
            dp[target] = ways;
        }
        return dp[T];
    }
    int combinationSum4(vector<int> &nums, int target)
    {
        int a = tabsolve(nums, target);
        return a;
    }
};