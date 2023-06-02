class Solution {
public:
    int spaceOptimized(string t1, string t2)
    {
        vector<int> curr(t2.length() + 1, 0);
        vector<int> next(t2.length() + 1, 0);
        for (int i = t1.size() - 1; i >= 0; i--)
        {
            for (int j = t2.size() - 1; j >= 0; j--)
            {
                if (t1[i] == t2[j]) curr[j] = 1 + next[j + 1];
                else
                {
                    int op1 = next[j];
                    int op2 = curr[j + 1];
                    curr[j] = max(op1, op2);
                }
            }
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string r = s;
        reverse(s.begin(),s.end());
        return spaceOptimized(r,s);
    }
};