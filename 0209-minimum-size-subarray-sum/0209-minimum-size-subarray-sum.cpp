class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        const int n = nums.size();
        int ans = INT_MAX;
        int l = 0,r = 0;
        int sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum>=target){
                     if(sum>=target){
                    ans = min(ans,r-l+1);
                    sum -= nums[l++];
                }
            }
            ++r;
        }
        if(ans==INT_MAX){return 0;}
        return ans;
    }
};