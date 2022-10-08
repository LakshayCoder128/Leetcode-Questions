class Solution
{
    public:
        int threeSumClosest(vector<int> &nums, int target)
        {
            sort(nums.begin(), nums.end());
            int diff = INT_MAX, sol = 0;
            int n = nums.size();
            for (int i = 0; i < n - 2; i++)
            {

                int k = i + 1;
                int j = n - 1;
                while (k < j)
                {
                    int ans = nums[i] + nums[k] + nums[j];
                    if (abs(ans - target) < diff)
                    {
                        diff = abs(ans - target);
                        sol = ans;
                    }

                    if (ans > target) j--;
                    else if (target > ans) k++;
                    else return ans;
                }
            }
            return sol;
        }
};