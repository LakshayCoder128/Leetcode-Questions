class Solution
{
    public:
        bool isSubsequence(string s, string t)
        {
            int st = 0;
            int n = t.size();
            
            if(s.size() == 0 && n == 0) return true;
            
            for (int i = 0; i < n; i++)
            {
                if (s[st] == t[i])
                {
                    st++;
                }

                if (st == s.size()) return true;
            }
            return false;
        }
};