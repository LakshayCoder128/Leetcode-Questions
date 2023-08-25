class Solution {
    private:
    bool solve(string &s1,int i, string &s2, int j,string &s3,int k,vector<vector<vector<int>>>&dp){
        if(k == s3.length())return true;
        if(dp[i][j][k] != -1)return dp[i][j][k];
        if(i < s1.size() && s1[i] == s3[k]  && j<s2.size() && s2[j] == s3[k]){
            return  dp[i][j][k]=solve(s1,i+1,s2,j,s3,k+1,dp) || solve(s1,i,s2,j+1,s3,k+1,dp);
        }
        else if(i < s1.size() && s1[i] == s3[k]){
            return  dp[i][j][k]=solve(s1,i+1,s2,j,s3,k+1,dp);
        }
        else if (j<s2.size() && s2[j] == s3[k]){ 
            return  dp[i][j][k]=solve(s1,i,s2,j+1,s3,k+1,dp);
        }
        else return  dp[i][j][k]=false;
    }
public:

    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size())return false;
        vector<vector<vector<int>>>dp(s1.size()+ 1, vector<vector<int>>(s2.size()+1,vector<int>(s3.size()+1,-1)));
        return solve(s1,0,s2,0,s3,0,dp);

        // int i=0,j=0,k=0;
        // while((i<s1.size() || j<s2.size()) && k < s3.size()){

        // }
    }

};