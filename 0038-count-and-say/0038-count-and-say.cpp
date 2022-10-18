class Solution
{
    public:
        string countAndSay(int n)
        {
            if (n == 1)
                return "1";
            if (n == 2)
                return "11";
            int k = 1;
            string p = "11", ans = "";
            for (int i = 3; i <= n; i++)
            {
                for (int i = 0; i <= p.length() - 1; i++)
                {
                    if (p[i] == p[i + 1])
                        k++;
                    else
                    {
                        ans += to_string(k);
                        ans += p[i];
                        k = 1;
                    }
                }
                p = ans;
                ans = "";
            }
            return p;
        }
};