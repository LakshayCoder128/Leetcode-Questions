class Solution {
public:
void solve(vector<int> &nums,int index,vector<int> &path,vector<vector<int>> &ans,int target)
{
      if(target==0)
      {
            ans.push_back(path);
            return;
      }
      for(int i=index;i<nums.size();i++)
      {
            if(i!=index&&nums[i-1]==nums[i])
            {
                  continue;
            }
            if(target<nums[i])
            {
                  break;
            }
            path.push_back(nums[i]);
            solve(nums,i+1,path,ans,target-nums[i]);
            path.pop_back();
            
      }


}
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
       
     
      sort(nums.begin(),nums.end());
      vector<int> path;
      vector<vector<int>> ans;
      solve(nums,0,path,ans,target);
      return ans;
    }
};