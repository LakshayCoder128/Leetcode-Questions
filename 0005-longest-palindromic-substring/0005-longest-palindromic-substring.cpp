class Solution {
public:
    string longestPalindrome(string s) {
        
        
        // Search through the middle approach 
        // T.C. -> O(n²)
        int start = 0;
        int resLen = 0;
        for(int i=0;i<s.length();i++){
            // odd 
            int left = i,right = i;
            while(left >=0 && right < s.length() && s[left] == s[right]){
                if(right - left +1 > resLen) {start = left;  resLen = right - left +1;}
                left --;
                right++;
            }
            
            // evenlen 
            left = i,right = i+1;
            while(left >=0 && right < s.length() && s[left] == s[right]){
                if(right - left +1 > resLen) {start = left;  resLen = right - left +1;}
                left --;
                right++;
            }
            
        }
        return s.substr(start , resLen);
        // Dp solution O(n²) + O(n²)
        /*
        int size = s.size();
        vector<vector<bool>>dp(size,vector<bool>(size));
        int start = 0,end = 0;
        int maxLen = 1;
        for(int col = 0;col <size ; col++){
            // for diagonal movement 
            for(int row = 0, cl = col ;cl < size ;row++,cl++){
                
                // if length == 1 
                if(col == 0) dp[row][cl] = true;
                // if length == 2
                else if (col == 1) {
                    if(s[row] == s[cl]) {
                        dp[row][cl] = true; 
                        maxLen = 2;
                        start = row;
                    }
                    else dp[row][cl] = false;
                }
                // other cases
                else {
                    if(s[row] == s[cl] && dp[row+1][cl -1] == true) {
                        dp[row][cl] = true;
                    }
                    else dp[row][cl] = false;
                }
                if(dp[row][cl]){
                    maxLen < col+1 ? maxLen = col+1,start = row :maxLen;
                    
                }
            }
        }
        return s.substr(start,maxLen);
        */
    }
};
