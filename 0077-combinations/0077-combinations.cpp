class Solution {
public:
    
    void solve(int k,int n,int ind,vector<int>&t,vector<vector<int>>&ans){
       
        if(k==0 ){ans.push_back(t);  return;}
       
        
        for(int i=ind ;i<=n;i++){
            t.push_back(i);
            solve(k-1,n,i+1,t,ans);
            t.pop_back();
        }
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>ans;
        vector<int>t;
        solve(k,n,1,t,ans);
        return ans;
    }
};