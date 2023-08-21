class Solution
{
    public:
        bool repeatedSubstringPattern(string s)
        {
            
            int i = 0;
            for (int j = 1; j < s.length(); j++) {
                string check = s.substr(0,j);
                string rep_Check = "";
                for(int i=0;i<s.length()/j;i++){
                    rep_Check += check;
                }
                if(rep_Check == s)return true;
            }
            return false;
        }
};