//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(n+1,1e9),parent(n+1);
        for(int i=1;i<n+1;i++){
            parent[i]=i;
        }
        dis[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int node=pq.top().second;
            int wt=pq.top().first;
            pq.pop();
            for(auto it:adj[node]){
                int adjnode=it.first;
                int adjweight=it.second;
                if(dis[adjnode]>wt+adjweight){
                    dis[adjnode]=wt+adjweight;
                    pq.push({dis[adjnode],adjnode});
                    parent[adjnode]=node;
                }
            }
        }
        if(dis[n]==1e9)return {-1};
        vector<int>ans;
        int node=n;
        while(parent[node]!=node){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends