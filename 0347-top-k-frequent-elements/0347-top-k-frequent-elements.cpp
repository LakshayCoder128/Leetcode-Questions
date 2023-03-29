// class Solution
// {
//     public:
//         vector<int> topKFrequent(vector<int> &nums, int k)
//         {
//             map<int, int> m;
//             for (auto i: nums) m[i]++;
//             priority_queue<pair<int, int>> pq;

//             for (auto i: m)
//             {
//                 pq.push({ i.second,
//                     i.first });
//             }
//             vector<int> ans;
//             for (int i = 0; i < k; i++)
//             {
//                 ans.push_back(pq.top().second);
//                 pq.pop();
//             }
//             return ans;
//         }
// };

class Solution
{
    public:
        vector<int> topKFrequent(vector<int> &nums, int k)
        {
            unordered_map<int, int> freq;
            for (auto num: nums) freq[num]++;

            vector<vector < int>> buckets(nums.size() + 1);
            for (auto[a, b]: freq)
                buckets[b].push_back(a);

            vector<int> res;
            for (int i = nums.size(); k; i--)
            {
                for (auto a: buckets[i])
                {
                    res.push_back(a);
                    k--;
                }
            }

            return res;
        }
};