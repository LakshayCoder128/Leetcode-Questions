class Solution
{
    public:
        void moveZeroes(vector<int> &nums)
        {
            if (nums.size() < 2) return;
            int i = 0, j = 1;
            while (j < nums.size() && i<nums.size())
            {
                if (nums[i] != 0) {i++;j=i+1;}
                else if (nums[j] == 0) j++;
                else swap(nums[i++], nums[j++]);
            }
        }
};