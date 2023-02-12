//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


string reverseWord(string str);


int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
	string s;
	cin >> s;
	
	cout << reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends


//User function Template for C++
string rev(string str,int s,int e){

if(s>=e)return str;

char temp = str[s];
str[s] = str[e];
str[e] = temp;
s++;
e--; 
return rev(str,s,e);
}
string reverseWord(string str){
    
//   int i=0,j=str.length()-1;
//   while(i<=j){
//       swap(str[i],str[j]);
//       i++;j--;
//   }
//   return str;
    int s = 0,e= str.length()-1;
    return rev(str,s,e);
}

