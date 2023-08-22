class Solution
{
    public:
        string convertToTitle(int columnNumber)
        {
            string ans = "";
            vector<char> data(27);
            for (int i = 0; i <= 25; i++)
            {
                data[i + 1] = 'A' + i;
            }
            data[0] = 'Z';
            int n = columnNumber;
            if (n < 27)
            {
                ans = 'A' + n - 1;
                return ans;
            }
            while (n > 0)
            {
                if (n % 26 == 0)
                {
                    ans += 'Z';
                    n -= 1;
                }
                else ans += 'A' + n % 26 - 1;
                n = n / 26;
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
};