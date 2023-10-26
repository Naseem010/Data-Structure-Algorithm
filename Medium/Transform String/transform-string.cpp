//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        //code here.
      vector<int>hash(256,0);
        vector<int>hash2(256,0);
        if(A.length()!=B.length())return -1;
        for(auto it:A){
            hash[it]++;
        }
        for(auto it:B){
            hash2[it]++;
        }
        for(int i=0;i<256;i++){
            if(hash[i]!=hash2[i])
              return -1;
        }
        int count=0;
        int i=A.length()-1;
        int j=B.length()-1;
        while(i>=0 && j>=0){
            if(A[i]==B[j]){
                i--;
                j--;
            }
            else {
                count++;
                i--;
            }
            
        }
        return count;
    }
};


//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends