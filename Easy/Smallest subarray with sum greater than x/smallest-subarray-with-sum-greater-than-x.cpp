//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here  
 int min = INT_MAX;
        
        int left = 0;
        int right = 0;
        int sum = 0;
        
        while(right<n)
        {
            if(arr[right] > x)
                return 1;
        
           sum+=arr[right];    
           
            
           if(sum > x)
           {
               while(sum>x)
               {
                   int index = (right - left) +1;
                   if(index < min)
                   {
                       min = index;
                   }
                   sum-=arr[left];
                   left++;
               }
           }
            
           right++;
        }
        
        return (min == INT_MAX)? 0:min;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends