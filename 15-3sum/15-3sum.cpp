class Solution
{
    public:
        vector<vector < int>> threeSum(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            vector<vector < int>> ans;

            for (int i = 0; i < n - 2 && nums[i]<=0 ; i++)
            {
                if (i > 0 && nums[i] == nums[i - 1]) continue;
                int s = i + 1;
                int e = n - 1;
                while (s < e)
                {
                    int sum = nums[i] + nums[s] + nums[e];
                    
                    if (sum < 0) s++;
                    else if (sum > 0) e--;
                    else
                    {
                        ans.push_back(vector <int>
                        {
                            nums[i],
                            nums[s],
                            nums[e] });
                        while (s + 1 < e && nums[s] == nums[s + 1]) s++;
                        while (s < e - 1 && nums[e] == nums[e - 1]) e--;
                        s++;
                        e--;
                    }
                }
            }
            return ans;
        }
};