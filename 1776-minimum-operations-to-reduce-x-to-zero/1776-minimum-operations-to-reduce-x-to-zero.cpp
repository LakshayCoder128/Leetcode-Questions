class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int tar = accumulate(nums.begin(),nums.end(),0);
        tar = tar - x;
        if(tar == 0)return nums.size();
        int currSum =0,max_len = 0,j =0;
        for(int i=0; i<nums.size();i++){
            currSum += nums[i];
            while(j<=i && currSum > tar){
                currSum -= nums[j];
                j++;
            }
            if(currSum == tar){
                max_len = max(max_len,i - j +1);
            }
        }

        return max_len ? nums.size()-max_len : -1;
    }
};