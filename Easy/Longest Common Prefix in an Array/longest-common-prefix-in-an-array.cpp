//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    
    string longestCommonPrefix (string arr[], int N)
    {
        // your code here
        string prev=arr[0];
        string str="";
        bool flag=true;
        for(int i=0;i<arr[0].size();i++){
            for(int j=0;j<N;j++){
                // char temp=prev[i];
                string curr=arr[j];
                if(curr[i]==prev[i]){
                    if(j==N-1){
                        str+=curr[i];
                    }
                    continue;
                }else{
                    flag=false;
                    break;
                }
                
            }
            if(flag==false)break;
        }
        if(str.empty())return "-1";
        return str;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        
        Solution ob;
        cout << ob.longestCommonPrefix (arr, n) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends