class Solution {
public:
    string breakPalindrome(string p) {
        if(p.length()==1) return "";

        for(int i=0;i<p.length()/2;i++)
        {
            if(p[i]!='a') 
            {
               p[i]='a'; 
               return p; 
            }
        }
        p[p.length()-1]='b';
        return p;
    }
};