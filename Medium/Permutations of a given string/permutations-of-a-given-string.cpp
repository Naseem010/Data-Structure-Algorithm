//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void help(string S,int index,set<string>&st){
	    if(index>=S.size()){
	        st.insert(S);
	        return;
	    }
	    for(int j=index;j<S.size();j++){
	        swap(S[index],S[j]);
	        help(S,index+1,st);
	        swap(S[index],S[j]);
	    }
	}
		vector<string>find_permutation(string S)
		{
		    vector<string>ans;
		    set<string>st;
		    int index=0;
		    help(S,index,st);
		  //  sort(ans.begin(),ans.end()); 
		  for(auto it:st){
		      ans.push_back(it);
		  }
		    return ans;
		    
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends