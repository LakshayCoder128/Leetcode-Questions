class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for(int i=0;i<2;i++){
            if(s1[i] == s2[i] || s1[i] == s2[i+2] ){
                if(s1[i] == s2[i]) continue;
                else {
                    swap(s2[i],s2[i+2]);
                }
            }
            else{
                return false;
            }
        }
        
        if(s1[3] == s2[3] && s1[2] == s2[2])
            return true;
        return false;
    }
};