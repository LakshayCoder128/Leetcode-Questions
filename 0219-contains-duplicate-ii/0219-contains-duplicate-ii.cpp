class Solution
{
    public:
        bool containsNearbyDuplicate(vector<int> &nums, int k)
        {
           	// set creation 
            unordered_set<int> s;

           	//edge cases
            if (k <= 0) return false;
            if (k > nums.size()) k = nums.size() - 1;

           	// sliding window
            for (int i = 0; i < nums.size(); i++)
            {
               	// window size check	// removal of out of window elements
                if (i > k) s.erase(nums[i - k - 1]);
               	// checking if repetition of element in the window
                if (s.find(nums[i]) != s.end()) return true;
               	// insertion if number is unique 
                s.insert(nums[i]);
            }

            return false;
        }
};