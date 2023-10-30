//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    void travel(vector<vector<string>> &list, vector<vector<string>> &ans, int i, vector<string> curr){ 
    
    if( i == list.size() ){
        ans.push_back(curr) ;
        return ;
    }   
    for(auto it : list[i]){
        curr.push_back(it);
        travel(list,ans,i+1,curr);
        curr.pop_back();
    }
       
}
    vector<vector<string>> sentences(vector<vector<string>>&list){
        //Write your code here
         vector<vector<string>> ans;
    travel(list, ans, 0, {});
    return ans;
    
    }
};


//{ Driver Code Starts.
int main()
{
	int t = 1;
	//cin>>t;
	while(t--)
	{
	    int m, n;
	    cin >> m >> n;
	    vector<vector<string>>list(m, vector<string>(n));
	    for(int i = 0 ; i < m; i++){
	        for(int j = 0; j < n; j++){
	            cin >> list[i][j];
	        }
	    }
	    Solution ob;
	    vector<vector<string>>ans = ob.sentences(list);
	    for(auto it : ans){
	        for(auto it1 : it){
	            cout << it1 << " ";
	        }
	        cout << endl;
	    }
	}
	return 0;
}

// } Driver Code Ends