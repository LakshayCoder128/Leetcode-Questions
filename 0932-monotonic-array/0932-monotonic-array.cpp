class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool monoInc= true,monoDec = true;
        // mono increasing
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                monoInc = false;
                break;
            }
        }
        if(monoInc == true)return true;
        // monodec
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] < nums[i]){
                monoDec = false;
                break;
            }
        }
        return monoDec;

    }
};