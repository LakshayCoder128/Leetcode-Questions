class Solution
{
    public:
        vector<vector < string>> groupAnagrams(vector<string> &strs)
        {
            unordered_map<string, vector < string>> m;
            for (auto i: strs)
            {
                vector<int> count(26);
                for (auto j:i)
                {
                    count[j - 'a']++;
                }
                string key = "";
                for (int i = 0; i < 26; i++)
                {
                    key.append(to_string(count[i] + 'a'));
                }
                m[key].push_back(i);
            }
            vector<vector < string>> result;
            for (auto it = m.begin(); it != m.end(); it++)
            {
                result.push_back(it->second);
            }
            return result;
        }
};