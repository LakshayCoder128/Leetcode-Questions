class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            int zerocnt = 0, ind = -1, pro = 1;
            for (int i = 0; i < nums.size(); i++)
            {
                if (nums[i] == 0)
                {
                    zerocnt++;
                    ind = i;
                }
                else pro *= nums[i];
            }

            for (int i = 0; i < nums.size(); i++)
            {
                if (zerocnt == 1)
                {
                    if (i != ind)
                        nums[i] = 0;
                    else nums[i] = pro;
                }
                else if (zerocnt > 1)
                {
                    nums[i] = 0;
                }
                else
                {
                    nums[i] = pro / nums[i];
                }
            }
            return nums;
        }
};