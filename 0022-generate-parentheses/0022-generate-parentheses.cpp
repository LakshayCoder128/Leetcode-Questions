class Solution
{
    public:

        void solve(int currOpen, int currClosed, string &a, vector<string> &ans, int n)
        {
            if (currOpen == n && currClosed == n)
            {
               	// ans.push_back({"()"});
                ans.push_back(a);
                return;
            }
           	// a.push_back('(');
            if (currOpen < n)
            {
                a.push_back('(');
                solve(currOpen + 1, currClosed, a, ans, n);

               	// back track
                a.pop_back();
            }
            if (currClosed < n && currOpen > currClosed)
            {
                a.push_back(')');
                solve(currOpen, currClosed + 1, a, ans, n);

               	// back track
                a.pop_back();
            }

           	
        }
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        string a = "(";
        solve(1, 0, a, ans, n);
        return ans;
    }
};