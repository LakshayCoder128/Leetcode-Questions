class Solution {
public:
    void solve(int n,string &a,int i){
        if(n==1) return ;
        // processing
        string t = "";
        for(int i=0;i<a.length();i++){
            if(a[i] == '0') t+="01";
            else if(a[i] == '1') t+="10";
        }
        a = t;
        solve(n-1,a,0);
    }
    int kthGrammar(int n, int k) {
        // string a = "0";
        // solve(n,a,0);
        // cout<<n<<" "<<a<<endl;
        // return a[k-1] == '0' ? 0:1;

        if(n==1 || k == 1) return 0;
        int mid = pow(2,n-2);
        if(k<=mid) return kthGrammar(n-1,k);
        else return !kthGrammar(n-1,k-mid);
    }
};