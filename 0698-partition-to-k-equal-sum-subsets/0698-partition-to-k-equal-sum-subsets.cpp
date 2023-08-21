class Solution {
    private:
    bool solve(vector<int>& nums, int k,int i,int sum,int target,vector<int>&vis){
        if(k == 1) return true;
        if(i>=nums.size())return false;
        if(sum == target) return solve(nums,k-1,0,0,target,vis);
        bool take = 0;
        if(sum + nums[i] <= target && vis[i] == 0){
            vis[i] = 1 ;
            take = solve(nums,k,i+1,sum+nums[i],target,vis);
            if(take)return true;
            vis[i] = 0;
        } 
        bool notTake = solve(nums,k,i+1,sum,target,vis);
        return take | notTake;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        for(auto &i:nums)sum+=i;  
        if(sum%k != 0 || nums.size() < k)return false;
        vector<int>vis(nums.size()+1,0);
        return solve(nums,k,0,0,sum/k,vis);
    }
};