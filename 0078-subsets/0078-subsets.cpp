class Solution
{
    public:

        void solve(vector<int> &nums, vector<vector< int >> &ans, vector< int > t, int ind)
        {
            if (ind == nums.size())
            {
                ans.push_back(t);
                return;
            }

           	// exclude 
            solve(nums, ans, t, ind + 1);
            
           	// include 
            t.push_back(nums[ind]);
            solve(nums, ans, t, ind + 1);
            
        }
    vector<vector < int>> subsets(vector<int> &nums)
    {
        vector<vector < int>> ans;
        vector<int> t;
        solve(nums, ans, t, 0);
        return ans;
    }
};