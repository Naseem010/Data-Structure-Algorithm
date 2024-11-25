//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        int n=arr.size();
        long long maxi=INT_MIN; ///striver explanation
	    long long prefix=1;
	    long long sufix=1;
	    for(int i=0;i<n;i++){
	         if(prefix==0)prefix=1; //if there is odd negative then we have to eliminate negative from prefix or sufix
	                                 // Can't eliminate negative from middle because it does not make observation to be maximum product
	      if(sufix==0)sufix=1;
	      prefix*=arr[i];
	      sufix*=arr[n-i-1];
	     
	      maxi=max(maxi,max(prefix,sufix));
	    }
	    return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends