//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool f(int i,int j,string &pattern, string &text){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(j<0 && i>=0){
            for(int ii=0;ii<=i;ii++){
                if(pattern[ii]!='*') return false;
            }
        }
        if(pattern[i]==text[j] || pattern[i]=='?')
        return f(i-1,j-1,pattern,text);
        
        if(pattern[i]=='*')
        return f(i-1,j,pattern,text) || f(i,j-1,pattern,text);
        
        return false;
    }
    bool match(string wild, string pattern)
    {
        // code here
            int n=wild.size();
        int m=pattern.size();
        return f(n-1,m-1,wild,pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends