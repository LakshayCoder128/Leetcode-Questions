// class Solution {
// public:
//     int jump(vector<int>& nums) {
        // int size = nums.size(),index = 1;
        // // base case 
        // // bcz we are alreafy on the last index
        // if(size == 1) return 0;
        // if(size == 2) return 1;
        // int n = size-1,ans = 0,maxi=nums[1];
        // for(int i=0;i<size-1;i++){
        //     maxi = -1;
        //     n=n-nums[i];
        //     ans++;
        //     if(n<=0) {
        //     return ans;
        //     }
        //     for(int j=index;j<=i+nums[i];j++){
        //         if(nums[j] >= maxi){
        //             maxi = nums[j];
        //             index = j;
        //         }
        //         if(n-nums[j] <= 0){
        //             ans++;
        //             return ans;
        //         }
        //     }
        //     n = n-maxi;
        //     ans++;
        //     if(n<=0) {
        //     return ans;
        //     }
        // }
        // return ans;

//         vector<int>dp(nums.size());
//         dp[num.size()-1] = 0;
//         int j = nums.size()-2;
      

//         return dp[nums.size()-1];
        

//     }
// };
        class Solution {
public:
    int jump(vector<int>& nums) {
        // The starting range of the first jump is [0, 0]
        int answer = 0, n = int(nums.size());

        int curEnd = 0, curFar = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest reachable index of this jump.
            curFar = max(curFar, i + nums[i]);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if (i == curEnd) {
                answer++;
                curEnd = curFar;
            }
        }
        
        return answer;
    }
};


/*
2 1 1 3 4
0 1 1 
*/