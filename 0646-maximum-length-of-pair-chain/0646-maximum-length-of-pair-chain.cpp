class Solution
{
    public:
        int findLongestChain(vector<vector < int>> &pairs)
        {
           	// custom sort according to the right value of pairs
            sort(pairs.begin(), pairs.end(), [](const vector<int> &first, const vector<int> &second)
            {
                return first[1] < second[1];
	});

            int end = INT_MIN, ans = 0;
            for (const auto &i: pairs)
            {
                if (i[0] > end)
                {
                    end = i[1];
                    ans++;
                }
            }
            return ans;
        }
};