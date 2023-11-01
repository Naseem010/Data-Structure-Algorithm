//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int target;
        cin >> target;
        
        cout << Search(vec,target) << "\n";
         
    }
}
// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> vec, int k) {
    //code here
    int low=0;
    int high=vec.size()-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(k==vec[mid])return mid;
        if(k==vec[low])return low;
        if(k==vec[high])return high;
        if(vec[mid]>vec[low]){                  //left half is sorted
            if(k>vec[low] && k<vec[mid] ){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }else if(vec[mid]<vec[low]){           // right half is sorted
            if(k>vec[mid] && k<vec[high]){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }else{                                  // Cannot determine which half is sorted
            low++;
            high--;
        }
    }
    return -1;
}