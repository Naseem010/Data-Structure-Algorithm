//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
    int n=str.size();
        vector<int>prev(n+1,0),cur(n+1,0);
        string s2=str;
        reverse(s2.begin(),s2.end());
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(str[i-1]==s2[j-1]) cur[j]=1+prev[j-1];
                else cur[j] = max(cur[j-1] ,prev[j]);
            }
            prev=cur;
        }
        return n-prev[n];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends