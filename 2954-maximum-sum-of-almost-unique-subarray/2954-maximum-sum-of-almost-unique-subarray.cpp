class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {

        long long maxi = 0;
        long long ans  = 0;
        unordered_map<int,int>mp;
        for(int i=0,j=0;i<nums.size();i++){
            int val = nums[i];
            
            mp[val]++;
            ans+=val;
            
            while(i-j+1 > k){
                int l = nums[j];
                mp[l]--;
                if(mp[l] == 0){
                    mp.erase(l);
                }
                ans-=l;
                j++;
            }
            if(mp.size() >= m){
            maxi = max(maxi,ans);
        }
        }
        
        return maxi;
    }
    
};