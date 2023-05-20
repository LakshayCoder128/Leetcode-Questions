class Solution
{
    public:
        void solve(int o, int c, int n, string temp, vector<string> &ans)
        {
            if (c == n)
            {
                ans.push_back(temp);
                return;
            }
            if (o < n) solve(o + 1, c, n, temp + '(', ans);
            if (c < o) solve(o, c + 1, n,temp + ')', ans);
        }
    vector<string> generateParenthesis(int n)
    {
        string temp;
        vector<string> ans;
        solve(0, 0, n, temp, ans);
        return ans;
    }
};