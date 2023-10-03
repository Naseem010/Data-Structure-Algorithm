//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int minimumNumberOfSwaps(string S){
        // code here 
 int open = 0;
        int closed = 0;
        
        int n = S.length();
        int count = 0;
        for(int i=0;i<n;i++){
            if(S[i]=='['){
                if(closed > open){
                    count += (closed-open);
                }
                open++;
            }else{
                open--;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0; 
} 
// } Driver Code Ends