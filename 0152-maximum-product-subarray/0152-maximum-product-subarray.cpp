class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int maxi = nums[0];
        int currMin = nums[0],currMax = nums[0],tempMax;

        for (int i = 1; i < nums.size(); i++)
        {
            // if(nums[i]==0) continue;

            tempMax = max(nums[i]*currMax,max(currMin*nums[i],nums[i]));
            currMin = min(nums[i]*currMax,min(currMin*nums[i],nums[i]));
            currMax = tempMax;
            maxi = max(maxi,currMax);

        }
        return maxi;
        
    }
};