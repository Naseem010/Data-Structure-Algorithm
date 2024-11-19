//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n=arr.size();
        int i,k=-1;
        for(i=n-1;i>0;i--){
            if(arr[i]>arr[i-1]){
                k=i-1;
                break;
            }
        };
        if(k==-1){
            sort(arr.begin(),arr.end());
            return;
        }
        vector<int>temp;
        for(int j=k;j<n;j++){
            temp.push_back(arr[j]);
        }
        sort(temp.begin(),temp.end());
        for(int j=0;j<temp.size();j++){
            if(temp[j]==arr[k] && temp[j]!=temp[j+1]){
                arr[k]=temp[j+1];
                k++;
                temp[j+1]=-1;
            break;
            }
        }
        for(int j=0;j<temp.size();j++){
            if(temp[j]!=-1){
                arr[k]=temp[j];
                k++;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int n = arr.size();
        ob.nextPermutation(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends