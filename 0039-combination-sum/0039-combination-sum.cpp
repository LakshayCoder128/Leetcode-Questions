class Solution
{
    public:
        void dfs(int i, vector<int> &curr, int total, int target, vector<vector< int >> &res, vector< int > &candidates)
        {
            if (total == target)
            {
                res.push_back(curr);
                return;
            }
            if (i >= candidates.size() || total > target) return;

            curr.push_back(candidates[i]);
            dfs(i, curr, total + candidates[i], target, res, candidates);
            curr.pop_back();
            dfs(i + 1, curr, total, target, res, candidates);
        }
    vector<vector < int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector < int>> res;
        vector<int> curr;
        int i = 0, total = 0;
        dfs(i, curr, total, target, res, candidates);
        return res;
    }
};