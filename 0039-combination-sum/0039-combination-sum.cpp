class Solution
{
    public:
        void solve(vector<int> &candidates, int target, vector<vector< int >> &ans, int index, vector< int > &temp)
        {
           	// base case 

            if (target < 0) return;
            if (target == 0)
            {
                ans.push_back(temp);
                return;
            }

           	// processing and call
            for (int i = index; i < candidates.size(); i++)
            {
                temp.push_back(candidates[i]);
                solve(candidates, target - candidates[i], ans, i, temp);
               	// back track
                temp.pop_back();
               	// solve(candidates,target,ans,i,temp);
            }
        }

    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> ans;
        vector<int> t;
        solve(candidates, target, ans, 0, t);
        return ans;
    }
};