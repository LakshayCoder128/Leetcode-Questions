class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        vector<int>ans;
        for(const auto &i:nums){
            m[i]++;
        }
        for(const auto &i:m){
            if(i.second > nums.size()/3)ans.push_back(i.first);
        }
        return ans;
    }
};