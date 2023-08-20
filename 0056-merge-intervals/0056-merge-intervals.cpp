class Solution
{
    public:
        vector<vector < int>> merge(vector<vector < int>> &intervals)
        {
            sort(intervals.begin(), intervals.end());

           	//   for (auto i : intervals) {
           	//     for (auto j : i) {
           	//       cout << j << " ";
           	//     }
           	//     cout << endl;
           	//   }
            vector<vector < int>> ans;
            int s = intervals[0][0];
            int e = intervals[0][1];
            for (int i = 1; i < intervals.size(); i++)
            {
                if (e >= intervals[i][0])
                {
                    e = max(e, intervals[i][1]);
                }
                else
                {
                    ans.push_back({ s,
                        e });
                    s = intervals[i][0];
                    e = intervals[i][1];
                }
            }
            ans.push_back({ s,
                e });
            return ans;
        }
};