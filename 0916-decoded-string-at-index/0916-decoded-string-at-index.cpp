class Solution {
public:
//     string decodeAtIndex(string s, int k) {
//         if(k == 1){
//             string a = "";a.push_back(s[0]);
//             return a;
//             }
//         string ans = "";
//         for(int i=0;i<s.length() && ans.length() < k+3;i++){
//             if(isdigit(s[i])){
//                 int t = s[i] - '0';
//                 string rep = ans;
//                 t--;
//                 while(t--){
//                     ans += rep;
//                 }
//             }
//             else ans += s[i];
//         }
//         // cout<<ans<<" ";
//         string a ;
//         a.push_back(ans[k-1]);
//         return a;
//     }
    string decodeAtIndex(string S, int K) {
        long N = 0, i;
        for (i = 0; N < K; ++i)
            N = isdigit(S[i]) ? N * (S[i] - '0') : N + 1;
        while (i--)
            if (isdigit(S[i]))
                N /= S[i] - '0', K %= N;
            else if (K % N-- == 0)
                return string(1, S[i]);
        return "";
    }
};