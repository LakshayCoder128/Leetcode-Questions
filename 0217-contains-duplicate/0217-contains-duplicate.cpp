class Solution
{
    public:
        bool containsDuplicate(vector<int> &nums)
        {
           	// brute force approach O(n2)

           	// for (int i = 0; i < nums.size() - 1; i++)
           	// {
           	//     for (int j = i + 1; j < nums.size(); j++)
           	//     {
           	//         if (nums[i] == nums[j]) return true;
           	//     }
           	// }
           	// return false;

           	// O(n) + O(n)
           	unordered_map<int, int> m;
           	for (auto i: nums)
           	{
           	    m[i]++;
           	    if (m[i] > 1) return true;
           	}
           	return false;

           	// sorting algo
            // sort(nums.begin(), nums.end());
            // for (int i = 0; i < nums.size() - 1; i++)
            // {
            //     if (nums[i] == nums[i + 1]) return true;
            // }
            // return false;
        }
};