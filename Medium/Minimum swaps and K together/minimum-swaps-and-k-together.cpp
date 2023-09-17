//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        //good value=GV
        // bad value=BV
        int l=0;
        int GV=0;
        int BV=0;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(arr[i]<=k){
                GV++;
            }
        }
        int i=0;
        int j=i+GV-1;
        for(int m=i;m<=j;m++){
                if(arr[m]>k)BV++;
            }
        while(j<n){
            mini=min(BV,mini);
            if(arr[i]>k)BV--;
            if(arr[j+1]>k)BV++;
            i++;
            j++;
            
        }
      return mini;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends