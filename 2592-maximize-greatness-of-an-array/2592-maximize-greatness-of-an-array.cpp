class Solution
{
    public:
        int maximizeGreatness(vector<int> &nums)
        {
            sort(nums.begin(), nums.end());
            int res = 0;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] > nums[res]) res++;
            }
            return res;

           	// 1 2 3 4
           	//   res = 0 1 2 3 
        }
};