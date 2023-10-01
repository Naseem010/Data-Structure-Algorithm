//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool exist(int i,int j,int n,int m,int s,vector<vector<char>>grid,string word,int x[],int y[]){
       
       for(int dir=0;dir<8;dir++){
        int tempi=i;
        int tempj=j;
        int cnt=0;
        int x1=x[dir];
        int y1=y[dir];
        while(tempi>=0 && tempi<n && tempj>=0 && tempj<m && cnt<s){
            if(word[cnt]==grid[tempi][tempj]){
                tempi+=x1;
                tempj+=y1;
                cnt++;
            }else{
                break;
            }
        }
        
     if(cnt==s)return true;
     
    }
    return false;
    }
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size();
	    int m=grid[0].size();
	    int s=word.size();
	    int x[8]={-1,0,1,1,1,0,-1,-1};
	    int y[8]={1,1,1,0,-1,-1,-1,0};
	    vector<vector<int>>ans;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(exist(i,j,n,m,s,grid,word,x,y)){
	                vector<int>temp;
	                temp.push_back(i);
	                 temp.push_back(j);
	                ans.push_back(temp);
	            }
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
		else
		{
		    for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		    }
		}
		
		
	}
	return 0;
}
// } Driver Code Ends