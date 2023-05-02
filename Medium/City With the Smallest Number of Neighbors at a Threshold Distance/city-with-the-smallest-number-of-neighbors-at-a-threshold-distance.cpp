//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,
                 int distanceThreshold) {
                     
                     vector<vector<int>>matrix(n,vector<int>(n,1e9));
                     for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               if(i==j)matrix[i][j]=0;
	            }
	        }
	        for(auto it:edges){
	           matrix[it[0]][it[1]]=it[2];
	             matrix[it[1]][it[0]]=it[2];
	        }
	            for(int via=0;via<n;via++){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                matrix[i][j]=min(matrix[i][j],matrix[via][j]+matrix[i][via]);
	            }
	        }
	    }
	    vector<int>temp(n,0);
	             for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	               if(matrix[i][j]<=distanceThreshold)temp[i]++;
	            }
	        }
	        int min=INT_MAX;
	        int ans;
	        for(int i=0;i<n;i++){
	            if(temp[i]<min)min=temp[i];
	        }
	          for(int i=0;i<n;i++){
	            if(temp[i]==min)ans=i;
	        }
	        return ans;
	    
                 }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends