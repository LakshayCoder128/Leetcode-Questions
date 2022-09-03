class Solution
{
    public:
        int lengthOfLastWord(string s)
        {
            int count = 0;
            int end = s.length() - 1;
            while (s[end] == ' ' && end >= 0)
            {
                end--;
                if (end < 0) return count;
            }

            while (s[end] != ' ' && end >= 0)
            {
                count++;
                end--;
                if (end < 0) return count;
            }
            return count;
        }
};