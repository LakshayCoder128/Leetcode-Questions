class Solution
{
    public:
        string addBinary(string a, string b)
        {
           	// two pointers

            int i = a.length() - 1, j = b.length() - 1, c = 0;
            int x, y;
            string res = "";
            while (i >= 0 || j >= 0 || c == 1)
            {
                x = i >= 0 ? a[i--] - '0' : 0;
                y = j >= 0 ? b[j--] - '0' : 0;
                int sum = x + y + c;
                res += sum % 2 + '0';
                c = sum / 2;
            }
            reverse(res.begin(), res.end());
            return res;
        }
};