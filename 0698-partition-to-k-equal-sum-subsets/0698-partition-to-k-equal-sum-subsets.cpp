// class Solution {
// public:
    
// bool helper(vector<int>& nums,int index,int &req,int sum,int k) {
//     if(k==0) {
//         return true;
//     }
//     if(sum==req) {
//         return helper(nums,0,req,0,k-1);
//     }
//     if(index>=nums.size()) {
//         return false;
//     }
//     if(nums[index]!=-1 && sum+nums[index]<=req) {
//         int n=nums[index];
//         nums[index]=-1;
//         if(helper(nums,index+1,req,sum+n,k)) {
//             return true;
//         }
//         nums[index]=n;
//         if(helper(nums,index+1,req,sum,k)) {
//             return true;
//         }
//         return false;
//     }
//     else {
//         return helper(nums,index+1,req,sum,k);
//     }
// }

// bool canPartitionKSubsets(vector<int>& nums, int K) {
//     int sum=0;
//     for(int i=0;i<nums.size();i++) {
//         sum+=nums[i];
//     }
//     if((sum%K)!=0) {
//         return false;
//     }
//     int req=sum/K;
//     return helper(nums,0,req,0,K);
// }

// };
class Solution {
public:
    bool dfs(vector<int>& nums,int ind, int k,int sum,int &target,vector<bool> &vis)
    {
        if(k==1)    return true; //rest of all nums sum equal to target
        if(ind==nums.size())    return false;
        if(sum==target) return dfs(nums,0,k-1,0,target,vis);//imp base case if current subset sum equal target then move to next subset
        bool pick=false;
        if(!vis[ind] && sum+nums[ind]<=target)
        {
            vis[ind]=true;
            pick=dfs(nums,ind+1,k,sum+nums[ind],target,vis);
            if(pick)return true;//we can stop here it will reduce height of decission tree | to avoid TLE
            vis[ind]=false;
        }
        bool npick=dfs(nums,ind+1,k,sum,target,vis);
        if(pick||npick)    return true;
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) 
    {
        int sum=0;
        for(int i:nums)
            sum+=i;
        if(sum%k!=0 || k>sum)    return false;
        sum/=k;
        vector<bool> vis(nums.size(),false);
        return dfs(nums,0,k,0,sum,vis);
    }
};