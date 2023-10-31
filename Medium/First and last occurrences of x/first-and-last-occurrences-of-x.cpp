//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int lowerbound(int arr[],int n,int x){
        int low=0;
        int high=n-1;
        int temp=n;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>=x){
               temp=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return temp;
    }
     int upperbound(int arr[],int n,int x){
         int temp=n;
          int low=0;
        int high=n-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid]>x){
                temp=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return temp;
     }
    vector<int> find(int arr[], int n , int x )
    {
        // code here
        vector<int>ans;
        int lb=lowerbound(arr,n,x);
        if(arr[lb]!=x || lb==n)return {-1,-1};
        int ub=upperbound(arr,n,x);
        ans.push_back(lb);
        ans.push_back(ub-1);
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends