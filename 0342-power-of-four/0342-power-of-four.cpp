class Solution {
public:
    bool isPowerOfFour(int n) {
        
        
        if(n<=0) return false;
        if(n==1) return true;
        double x = log2(n)/log2(4);
        
        int power = pow(4,int(x));
        
        if(power == n) return true;
        else return false;
    }
};