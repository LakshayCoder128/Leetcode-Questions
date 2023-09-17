class Solution {
public:
    string multiply(string num1, string num2) {
        int a = num1.size();
        int b = num2.size();
        
        // create a string value that is include the result
        string res(a+b, '0');

        // multiply values with each other by running for loop
        // substracting '0' from string char number makes it integer
        for(int i=a-1; i>=0; i--) {
            for(int j=b-1; j>=0; j--) {
                int di = (num1[i] - '0') * (num2[j] - '0') + (res[i+j+1]-'0');
                res[i+j+1] = di % 10 + '0';
                res[i+j] += di/10;
            }
        }

        // check if there is it start with zero

        for(int i=0; i<res.size(); i++) {
            if(res[i]!='0') return res.substr(i);
        }
        return "0";

    }
};