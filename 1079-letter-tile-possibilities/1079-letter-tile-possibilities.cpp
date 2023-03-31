class Solution
{
    public:
        void solve(string &tiles, string &output, map<int, bool> used_or_not, set<string> &unique_strings)
        {

            for (int i = 0; i < tiles.size(); i++)
            {
                if (used_or_not[i] == 0)
                {
                    output.push_back(tiles[i]);
                    used_or_not[i] = 1;
                    
                    unique_strings.insert(output);
                    solve(tiles, output, used_or_not, unique_strings);
                    
                    output.pop_back();
                    used_or_not[i] = 0;
                }
            }
        }
    int numTilePossibilities(string tiles)
    {
        map<int, bool> used_or_not;
        set<string> unique_strings;
        string output = "";

        solve(tiles, output, used_or_not, unique_strings);

        return unique_strings.size();
    }
};