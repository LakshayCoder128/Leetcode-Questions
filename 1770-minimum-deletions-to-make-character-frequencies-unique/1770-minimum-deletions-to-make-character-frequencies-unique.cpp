class Solution
{
    public:
        int minDeletions(string s)
        {
            int fre[26] = { 0 };
            for (const auto &i: s) fre[i - 97]++;
            int del = 0;
            set<int> st;
            for (int i = 0; i < 26; i++)
            {
                while (fre[i] && st.find(fre[i]) != st.end())
                {
                    del++;
                    fre[i]--;
                }
                st.insert(fre[i]);
            }
            return del;
        }
};