class Solution
{
    public:
        int sol1(vector<int> &nums, int x)
        {
            int minAns = INT_MAX;
            for (int i = 0; i < nums.size() - x; i++)
            {
                for (int j = i + x; j < nums.size(); j++)
                {
                    int diff = abs(nums[i] - nums[j]);
                    minAns = min(minAns, diff);
                }
            }
            return minAns;
        }
    int sol2(vector<int> &nums, int x)
    {

        set<int> s;
        int res = INT_MAX;
        for (int i = x; i < nums.size(); ++i)
        {
            s.insert(nums[i - x]);
            auto it = s.upper_bound(nums[i]);
            if (it != begin(s))
                res = min(res, nums[i] - *prev(it));
            if (it != end(s))
                res = min(res, *it - nums[i]);
        }
        return res;
    }

    int minAbsoluteDifference(vector<int> &nums, int x) {return sol2(nums,x);}
};