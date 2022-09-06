class Solution
{
    public:
        bool checkDistances(string s, vector<int> &distance)
        {
            // map<char, int> m;
            // for (int i = 0; i < s.length(); i++)
            // {
            //     m[s[i]]++;
            // }

            for (int i = 0; i < s.length(); i++)
            {
                int index = s[i] - 'a';
                // if (m[s[i]] > 1)
                {
                    for (int j = i + 1; j < s.length(); j++)
                    {
                        if (s[i] == s[j])
                        {
                            if (distance[index] != j - i - 1)
                            {
                                return false;
                            }
                        }
                    }
                }
//                 
            }
            return true;
        }
};