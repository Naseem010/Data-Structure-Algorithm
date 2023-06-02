//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        // Code here
        vector<pair<int,int>>adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int>cost(n,1e9);
        cost[src]=0;
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int steps=q.front().first;
            int node=q.front().second.first;
            int costs=q.front().second.second;
            q.pop();
            // if(node==dst && steps==K+1)return cost;
            if(steps>K)continue;
            for(auto it:adj[node]){
                int ncost=it.second;
                int newnode=it.first;
                if(cost[newnode]>costs+ncost){
                    
                q.push({steps+1,{newnode,costs+ncost}});
                cost[newnode]=costs+ncost;
                }
            }
        }
        for(int i=0;i<n;i++){
            if(cost[i]==1e9)cost[i]=-1;
        }
        return cost[dst];
}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n; cin>>n;
        int edge; cin>>edge;
        vector<vector<int>> flights;
        
        for(int i=0; i<edge; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            flights.push_back(temp);
        }
        
        int src,dst,k;
        cin>>src>>dst>>k;
        Solution obj;
        cout<<obj.CheapestFLight(n,flights,src,dst,k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends