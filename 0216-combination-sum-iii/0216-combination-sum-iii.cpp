class Solution {
public:
    
    void solve(int k,int n,int ind,vector<int>&t,vector<vector<int>>&ans){
        // cout<< " k : "<<k <<" n : "<<n<<" ind: "<<ind<<endl;
        if(k==0 && n==0){ans.push_back(t);  return;}
        if(k==0 || n<0 || ind > n  ) return ;
        
        for(int i=ind ;i<=9;i++){
            t.push_back(i);
            solve(k-1,n-i,i+1,t,ans);
            t.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>t;
        solve(k,n,1,t,ans);
        return ans;
    }
};