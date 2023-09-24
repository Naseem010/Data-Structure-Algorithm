//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Your code goes here
        // sort(a,a+n);
        // sort(b,b+m);
        //  set<int>s;
        // int i,j=0;
        // // set<int>s;
        // while(i<n && j<m){
        //     if(a[i]<b[j]){
        //         i++;
        //     }else if(a[i]>b[j]){
        //         j++;
        //     }else if(a[i]==b[j]){
        //         s.insert(a[i]);
        //         i++;
        //         j++;
        //     }
        // }
        
        // return s.size();
         sort(a,a+n);
        sort(b,b+m);
       set<int>s;
        int j=0;
        int k=0;
        while(j<n && k<m){
            if(a[j]>b[k]){
                k++;
            }
            else if(a[j]<b[k])j++;
            else if(a[j]==b[k]){
                s.insert(a[j]);
                j++;
                k++;
        }
        }
        return s.size();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends