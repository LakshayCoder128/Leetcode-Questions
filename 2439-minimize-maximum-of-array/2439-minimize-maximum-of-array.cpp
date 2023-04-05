class Solution
{
    public:
        int minimizeArrayValue(vector<int> &nums)
        {
            long long pre = 0, ans = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                pre += nums[i];
                ans = max(ans, (pre + i) / (i + 1));
            }
            return ans;
        }
};
