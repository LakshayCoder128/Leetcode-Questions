class Solution
{
    public:
        bool check(string &s, int i, int j)
        {
            while (i < s.length() && !iswalnum(s[i]))
                i++;
            while (j >= 0 && !iswalnum(s[j]))
                j--;
            if (i >= j) return true;
            if (tolower(s[i]) == tolower(s[j])) return check(s, i + 1, j - 1);
            else return false;
        }
    bool isPalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        return check(s, i, j);
    }
};