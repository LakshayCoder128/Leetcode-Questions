class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<bool>>dp(n,vector<bool>(n));
        int count = 0;
        for(int Dcol = 0;Dcol < n ;Dcol ++ ){
            // diagonal traversal
            
            for(int row = 0,col = Dcol ;col < n ;row++,col++){
                // len = 1
                if(Dcol == 0) dp[row][col] = true;
                // len =2
                else if(Dcol == 1){
                    if(s[row] == s[col]) dp[row][col] = true;
                    else dp[row][col]= false;
                }
                // other cases
                else {
                    if(s[row]== s[col] && dp[row+1][col-1] == true){
                        dp[row][col] = true;
                    }
                    else dp[row][col]=false;
                }
                
                if(dp[row][col]) count++;
            }
        }
        return count;
    }
};