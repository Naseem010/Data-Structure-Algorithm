class Solution {
public:
void bfs(vector<vector<char>> grid,vector<vector<int>>& vis,int i,int j){
    int row=grid.size();
    int col=grid[0].size();
    vis[i][j]=1;
    queue<pair<int,int>>q;
    q.push({i,j});
    while(!q.empty()){
        int i1=q.front().first;
        int j1=q.front().second;
        q.pop();
        for(int delrow=-1;delrow<=1;delrow++){
            int newrow=i1+delrow;
            int newcol=j1;
            if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && !vis[newrow][newcol] && grid[newrow][newcol]=='1'){
                q.push({newrow,newcol});
                vis[newrow][newcol]=1;
            }
        }
        for(int delcol=-1;delcol<=1;delcol++){
            int newrow=i1;
            int newcol=j1+delcol;
            if(newrow>=0 && newrow<row && newcol>=0 && newcol<col && !vis[newrow][newcol] && grid[newrow][newcol]=='1'){
                q.push({newrow,newcol});
                vis[newrow][newcol]=1;
            }
        }
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
int cnt=0;
        vector<vector<int>>vis(row,vector<int>(col,0));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(grid,vis,i,j);
                }
            }
        }
return cnt;
    }
};