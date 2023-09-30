//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(int i, int j,int n, int m, vector<vector<char>>&mat,string target,int index){
        int found=0;
        if(i>=0 && j>=0 && i<n && j<m && mat[i][j]==target[index]){
            char temp=target[index];
            index++;
            mat[i][j]=0;
            if(index==target.size()){
                found=1;
            }
            else{
                found+=solve(i+1,j,n,m,mat,target,index);
                found+=solve(i-1,j,n,m,mat,target,index);
                found+=solve(i,j+1,n,m,mat,target,index);
                found+=solve(i,j-1,n,m,mat,target,index);
            }
            mat[i][j]=temp;
        }
        return found;
    }
    int findOccurrence(vector<vector<char> > &mat, string target){
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=0,ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans+=solve(i,j,n,m,mat,target,0);
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
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}

// } Driver Code Ends