//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>>adj[n];
          int mod=(int)(1e9+7);
        for(auto it:roads){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
      
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>ways(n,0);
        vector<int>dis(n,2e9);
        ways[0]=1;
        dis[0]=0;
        pq.push({0,0});
        while(!pq.empty()){ 
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjwt=it.second;
            
                if(dis[adjnode]>adjwt+dist){
                    dis[adjnode]=adjwt+dist;
                    pq.push({dist+adjwt,adjnode});
                    ways[adjnode]=ways[node];
                }
                else if(adjwt+dist==dis[adjnode]){
                    ways[adjnode]=(ways[adjnode]+ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
     
 
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends