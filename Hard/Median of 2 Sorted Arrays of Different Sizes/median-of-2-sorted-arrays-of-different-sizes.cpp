//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
    //     int n1=array1.size();
    //     int n2=array2.size();
    //     vector<int>arr;
    //   int i,j=0;
    //   while(i<n1 && j<n2){
    //       if(array1[i]>array2[j]){
    //           arr.push_back(array2[j]);
    //           j++;
    //   }else if(array1[i]<=array2[j]){
    //       arr.push_back(array1[i]);
    //       i++;
    //   }
    //   }
    //   while(i<n1){
    //       arr.push_back(array1[i]);
    //       i++;
    //   }
    //   while(j<n2){
    //       arr.push_back(array2[j]);
    //       j++;
    //   }
       
    //     int k=arr.size()/2;
    //     if(arr.size()%2!=0){
    //         return double(arr[k]);
    //     }else{
    //         double ans=(double(arr[k])+double(arr[k-1]))/2.0;
    //         return ans;
    //     }
      if(array2.size() < array1.size()) 
        return MedianOfArrays(array2,array1);
        
        int n1 = array1.size();
        int n2 = array2.size();
        int low = 0, high = n1;
        
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 == 0 ? INT_MIN : array1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : array2[cut2-1];
            
            int right1 = cut1 == n1 ? INT_MAX : array1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : array2[cut2];
            
            if(left1 <= right2 && left2 <= right1){
                if((n1+n2)%2 == 0)
                return (max(left1,left2)+ min(right1,right2))/2.0;
                else 
                return max(left1,left2);
            }
            else if(left1 > right2) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
    return 0.0;
    
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends