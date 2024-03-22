//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector <int> nFibonacci(int N){
        //code here
    vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        int i = 1;
        while(true)
        {
            if(N < ans[i])
            {
                break;
            }
            else{
                i++;
                ans.push_back(ans[i-1]+ans[i-2]);
            }
        }
        ans.pop_back();
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        Solution ob;
        vector <int> ans=ob.nFibonacci(N);
        for(int u:ans)
         cout<<u<<" ";
        cout<<"\n"; 
    }
}
// } Driver Code Ends