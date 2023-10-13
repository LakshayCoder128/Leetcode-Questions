class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0,j=nums.size()-1;
        int m;
        while(s<j){
            m = s+ (j-s)/2;
            if(nums[m+1] < nums[m] ){
                j = m;
            }
            else{
                s = m+1;
            }
        }
        return s;
    }
};