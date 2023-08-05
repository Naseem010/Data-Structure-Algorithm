//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    void segregateElements(int arr[],int n)
    {
        // Your code goes here
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<n;i++){
            if(arr[i]>=0){
                arr1.push_back(arr[i]);
            }
            else{
                arr2.push_back(arr[i]);
            }
        }
        int p=arr1.size();
        int q=arr2.size();
        int j=0;
           for(int i=0;i<n;i++){
                if(i>=p){
                    arr[i]=arr2[j];
                    j++;
                }
                else{
                    arr[i]=arr1[i];
                }
        }
    }
};

//{ Driver Code Starts.
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		ob.segregateElements(a,n);
		
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
		cout<<endl;
	}
}

// } Driver Code Ends