//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        vector<int>temp=arr[0];
        int ps=arr[0][0];
        int pe=arr[0][1];
        for(int i=1;i<arr.size();i++){
            int cs=arr[i][0];
            int ce=arr[i][1];
            if(cs<=pe){
                if(ce>pe){
                    temp[0]=ps;
                    temp[1]=ce;
                    ps=temp[0];
                    pe=temp[1];
                }else if(ce<pe){
                    continue;
                }
            }
            else if(cs>pe){
                ans.push_back(temp);
                temp=arr[i];
                ps=temp[0];
                pe=temp[1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<vector<int>> arr(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            arr[i].push_back(x);
            arr[i].push_back(y);
        }
        Solution obj;
        vector<vector<int>> ans = obj.mergeOverlap(arr);
        for (auto i : ans) {
            for (auto j : i) {
                cout << j << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends