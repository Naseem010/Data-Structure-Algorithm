//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


vector<int> Smallestonleft(int arr[], int n);


int main() {
	
	int t;
	
	cin >> t;
	
	while(t--){
	    
	    int n;
	    cin >> n;
	    int arr[n+1];
	    
	    for(int i=0;i<n;i++){
	        cin>> arr[i];
	    }
	    
	    vector<int> b;
	    b = Smallestonleft(arr, n);
	    for(int i=0;i<n;i++)
	        cout << b[i] << " ";
	       
	    cout << endl;
	    
	    
	}
	
	return 0;
}
// } Driver Code Ends


vector<int> Smallestonleft(int arr[], int n)
{
    // Complete the function
    // set<int>st;
    // vector<int>ans;
    // ans.push_back(-1);
    // st.insert(arr[0]);
    // for(int i=1;i<n;i++){
    //     st.insert(arr[i]);
        
           vector<int>ans(n,-1);
    set<int>temp;
    temp.insert(arr[0]);
   
    for(int i=1;i<n;i++)
    {
        vector<int>temp1(temp.begin(),temp.end());
        int index=lower_bound(temp1.begin(),temp1.end(),arr[i])-temp1.begin();
        if(index-1>=0)
        ans[i]=temp1[index-1];
        
        temp.insert(arr[i]);
    }
    return ans ;
    
}