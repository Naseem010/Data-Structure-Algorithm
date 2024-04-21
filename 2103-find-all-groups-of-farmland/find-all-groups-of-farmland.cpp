class Solution {
public:
vector<int> bfs(vector<vector<int>>& land,vector<vector<int>>& vis ,int row,int col,vector<vector<int>>& ans){
   int n=land.size();
   int m=land[0].size();
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    int minrow=row;
    int mincol=col;
    int maxrow=row;
    int maxcol=col;
   
    
    while(!q.empty()){
         int currRow=q.front().first;
         int currCol=q.front().second;
        q.pop();
        for(int delrow=-1;delrow<=1;delrow++){
            int newrow=delrow+currRow;
            int newcol=currCol;
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && land[newrow][newcol]==1 && !vis[newrow][newcol]){
                vis[newrow][newcol]=1;
                q.push({newrow,newcol});
                minrow=min(minrow,newrow);
                mincol=min(mincol,newcol);
                maxrow=max(newrow,maxrow);
                maxcol=max(newcol,maxcol);
            }
        }
         for(int delcol=-1;delcol<=1;delcol++){
            int newrow=currRow;
            int newcol=currCol+delcol;
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m && land[newrow][newcol]==1 && !vis[newrow][newcol]){
                vis[newrow][newcol]=1;
                q.push({newrow,newcol});
                minrow=min(minrow,newrow);
                mincol=min(mincol,newcol);
                maxrow=max(newrow,maxrow);
                maxcol=max(newcol,maxcol);
            }
        }

    }
   return {minrow,mincol,maxrow,maxcol};

}
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>>ans;
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(land[i][j]==1 && !vis[i][j]){
                   vector<int>temp= bfs(land,vis,i,j,ans);
                   ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};