class Solution
{
    public:
        vector<int> productExceptSelf(vector<int> &nums)
        {
            //O(n+1) with division operator
//             int zerocnt = 0, ind = -1, pro = 1;
//             for (int i = 0; i < nums.size(); i++)
//             {
//                 if (nums[i] == 0)
//                 {
//                     zerocnt++;
//                     ind = i;
//                 }
//                 else pro *= nums[i];
//             }

//             for (int i = 0; i < nums.size(); i++)
//             {
//                 if (zerocnt == 1)
//                 {
//                     if (i != ind)
//                         nums[i] = 0;
//                     else nums[i] = pro;
//                 }
//                 else if (zerocnt > 1)
//                 {
//                     nums[i] = 0;
//                 }
//                 else
//                 {
//                     nums[i] = pro / nums[i];
//                 }
//             }
//             return nums;
            
            
            // O(n+n)
            vector<int>prefix(nums.size(),1);
            vector<int>postfix(nums.size(),1);
            
            prefix[0] = nums[0];
            postfix[nums.size()-1] = nums[nums.size()-1];
            for(int i=1;i<nums.size();i++) prefix[i] = prefix[i-1]*nums[i];
            
            for(int i=nums.size()-2;i>=0;i--){
                postfix[i] = postfix[i+1]*nums[i];
            }
            nums[0] = postfix[1];
            nums[nums.size()-1] = prefix[nums.size()-2];
            for(int i=1;i<nums.size()-1;i++){
                nums[i] = postfix[i+1] * prefix[i-1];
            }
            return nums;
        }
};