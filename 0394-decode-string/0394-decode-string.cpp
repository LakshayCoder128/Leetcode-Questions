class Solution
{
    public:
        string solve(string &s, int &i)
        {
           	// if(i == s.length())return;
            string res;
            while (i < s.length() && s[i] != ']')
            {
                if (!isdigit(s[i]))
                {
                    res += s[i];
                    i++;
                }
                else
                {
                    int dig = 0;

                    while (i < s.length() && isdigit(s[i]))
                    {
                        dig = dig *10 + s[i] - '0';
                        i++;
                    }
                    i++;	// opening brace will be there
                    string t = solve(s, i);	// repeating string between[ ..... ] untill we have another digit or end of the string
                    i++;	//  closing brace

                   	// add the string digit number of times into res

                    while (dig-- > 0)
                    {
                        res += t;
                    }
                    
                }
            }
            return res;
        }
    string decodeString(string s)
    {
        int i=0;
        return solve(s, i);
    }
};