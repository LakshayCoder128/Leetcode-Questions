class Solution
{
    public:
        bool isAnagram(string s, string t)
        {
            /*
            T.C. -> O(2*nlogn)   S.C. -> 2*logn
            if(s.length() != t.length()) return false;
            sort(s.begin(),s.end());
            sort(t.begin(),t.end());

            for(int i=0;i < s.length();i++){
                if(s[i] != t[i])return false;
            }
            return true;
            */

           	// map  T.C. O(2*n) + SC = O(2*n)
            if (s.length() != t.length()) return false;
            unordered_map<char, int> sm;
            unordered_map<char, int> tm;

            for (int i = 0; i < s.length(); i++)
            {
                sm[s[i]]++;
                tm[t[i]]++;
            }

            for (int i = 0; i < sm.size(); i++)
            {
                if (sm[i] != tm[i]) return false;
            }
            return true;
        }
};