//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    vector<int> Series(int n) {
        // Code here
        vector<int>ans;
        int mod=1000000007;
        if(n==0)ans.push_back(0);
        else if(n==1){
            ans.push_back(0);
            ans.push_back(1);
        }else{
            ans.push_back(0);
            ans.push_back(1);
            for(int i=2;i<=n;i++){
                int num=(ans[i-1]+ans[i-2])%mod;
                ans.push_back(num);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends