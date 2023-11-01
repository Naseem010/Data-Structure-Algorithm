//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        // code here
        int temp=sqrt(N);
        int count =0;
        if(temp*temp==N){
        for(int i=1;i<temp;i++){
            count++;
        }
        }else{
            for(int i=1;i<=temp;i++){
            count++;
        }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends