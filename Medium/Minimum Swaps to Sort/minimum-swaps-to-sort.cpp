//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>>v;
	    for(int i=0;i<nums.size();i++){
	        v.push_back({nums[i],i});
	    }
	    sort(v.begin(),v.end());
	    int count=0;
	    for(int i=0;i<v.size();i++){
	        if(i==v[i].second)continue;
	        else{
	            count++;
	            swap(v[v[i].second],v[i]);
	            i--;
	        }
	    }
	    return count;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends