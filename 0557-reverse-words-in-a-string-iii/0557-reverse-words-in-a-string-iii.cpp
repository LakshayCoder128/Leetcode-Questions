class Solution {
public:
    string reverseWords(string s) {
        int b = 0,e = -1;
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                e = i;
                reverse(s.begin()+b , s.begin()+e);
                b = i+1;
            }
        }
        reverse(s.begin()+b,s.end());
        return s;
    }
};