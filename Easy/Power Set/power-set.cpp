//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    int n=pow(2,s.size());
		    vector<string>ans;
		    for(int i=1;i<n;i++){
		        string temp="";
		        int j=0;
		        int x=i;
		        while(x){
		            if(x&1){
		                temp+=s[j];
		            }
		            j++;
		            x=x>>1;
		        }
		        ans.push_back(temp);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}
// } Driver Code Ends