class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // works for single duplicates only
        // int a =0;
        // for(int i=0;i<nums.size();i++){
        //     a = a ^ nums[i];
        // }
        // for(int i=1;i<nums.size();i++){
        //     a = a^i;
        // }
        // return a;
        
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==nums[i]){
                return nums[i];
            }
        }
        return -1;
    }
};