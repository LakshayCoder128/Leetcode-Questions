class Solution {
public:
    int numDecodings(string s) {
        // size nikalo
        int len = s.length();
        // single length edge case handling
        if(len == 1) {if(s[0]>'0') return 1; else return 0;}
        if(len < 1) return 0;
        // dp initialize
        
        vector<int>dp(len);
        // start from end
        for(int i=len-1;i>=0;--i){
        // check karo ki aage element hai ki nhi ? nhi hai to 1 otherwise hai to dp[i+1]
            if(s[i]>'0')
            {
                dp[i] = i+1 < len ? dp[i+1] : 1;
            
             if(i+1 < len && (s[i]=='1' || (s[i] == '2' && s[i+1] <= '6'))){
                    // check karo 1 & 2 mein se koi hai + i+1 wale mein <= 6 hai 
                    //  agr haan to i+2 tak check kro 
                 dp[i] += i+2<len ? dp[i+2] : 1;
             }
            }
        }
        return dp[0];

    }
};