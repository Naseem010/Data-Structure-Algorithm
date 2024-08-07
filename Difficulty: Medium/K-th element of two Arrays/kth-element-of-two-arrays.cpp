//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        vector<int>arr;
        int i=0,j=0;
        int n1=arr1.size();
        int n2=arr2.size();
        while(i<n1 && j<n2){
            if(arr1[i]>arr2[j]){
                arr.push_back(arr2[j]);
                j++;
            }else if(arr1[i]<arr2[j]){
                arr.push_back(arr1[i]);
                i++;
            }else{
                arr.push_back(arr1[i]);
                arr.push_back(arr2[j]);
                i++;
                j++;
            }
        }
       while(i<n1){
           arr.push_back(arr1[i]);
           i++;
       }
       while(j<n2){
           arr.push_back(arr2[j]);
           j++;
       }
       return arr[k-1];
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends