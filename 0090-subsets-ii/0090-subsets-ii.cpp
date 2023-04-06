class Solution
{
    public:
        void solve(vector<int> nums, vector<int> &output, int index, vector< vector< int>> &ans)
        {
            ans.push_back(output);

            for (int i = index; i < nums.size(); i++)
            {

                if (i > index && nums[i] == nums[i - 1]) continue;
               	// include
                output.push_back(nums[i]);
                solve(nums, output, i + 1, ans);
                output.pop_back();
            }
        }
    vector<vector < int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector < int>> ans;
        vector<int> output;
        int index = 0;
       	sort(nums.begin(),nums.end());
        solve(nums, output, index, ans);
        return ans;
    }
};