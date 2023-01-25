class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longest = 0;
        
        for(int i : nums) 
            s.insert(i);
        
        for(int i : nums)
        {
            // Find begin of new sequence. When i-1 not exist in set - i is start of new sequence
            if(s.find(i-1) == s.end())
            {
                int current = 1;
                while(s.find(i+current) != s.end())
                    ++current;
                longest = current > longest ? current : longest;
            }
        }
        
        return longest;
    }
};