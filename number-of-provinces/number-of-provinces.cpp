class Solution {
public:
void dfs(int node,vector<int>&vis,vector<int>adjls[]){
    vis[node]=1;
    for(auto it:adjls[node]){
        if(!vis[it]){
            dfs(it,vis,adjls);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vector<int>adjls[n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        int cnt=0;
        vector<int>vis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,vis,adjls);
            }
        }
        return cnt;
    }
};