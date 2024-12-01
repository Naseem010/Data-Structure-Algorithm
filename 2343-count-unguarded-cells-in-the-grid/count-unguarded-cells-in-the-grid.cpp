class Solution {
public:
vector<int>x={-1,0,1,0};
vector<int>y={0,1,0,-1};
void dfs(vector<vector<int>>&matrix,int i,int j,int m,int n){
//     if(i<0 || i>=m || j<0 || j>=n)return;
// if(matrix[i][j]==3)return;
// if(matrix[i][j]==0){
//     matrix[i][j]=1;
// }
// for(int k=0;k<4;k++){
//     int i=i+x[k];
//     int j=j+y[k];
//     dfs(matrix,i,j,m,n);
// }

for(int k=j-1;k>=0;k--){
    if(matrix[i][k]==0)matrix[i][k]=1;
    else if(matrix[i][k]==3 || matrix[i][k]==2)break;
}
for(int k=j+1;k<n;k++){
    if(matrix[i][k]==0)matrix[i][k]=1;
    else if(matrix[i][k]==3 || matrix[i][k]==2)break;
}
for(int k=i-1;k>=0;k--){
    if(matrix[k][j]==0)matrix[k][j]=1;
    else if(matrix[k][j]==3 || matrix[k][j]==2)break;
}
for(int k=i+1;k<m;k++){
    if(matrix[k][j]==0)matrix[k][j]=1;
    else if(matrix[k][j]==3 || matrix[k][j]==2)break;
}
}
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        //0-->unguarded
        //1-->guarded
        //2-->guardPresent
        //3-->wallPresent
        vector<vector<int>>matrix(m,vector<int>(n,0));
        for(int i=0;i<guards.size();i++){
            int x=guards[i][0];
            int y=guards[i][1];
            matrix[x][y]=2;
        }
        for(int i=0;i<walls.size();i++){
            int x=walls[i][0];
            int y=walls[i][1];
            matrix[x][y]=3;
        }
        
       for(int k=0;k<guards.size();k++){
         int i=guards[k][0];
         int j=guards[k][1];
         dfs(matrix,i,j,m,n);
        }
        int cnt=0;
         for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                   cnt++;
                }
            }
        }
        return cnt;
    }
};