//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here  
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        int ans=INT_MAX;
        for(auto it:str){
            mp1[it]++;
        }
        int i=0,j=0;
        while(j<str.size()){
            // string temp=str[j];
            mp2[str[j]]++;
            while(mp2.size()==mp1.size()){
                ans=min(ans,(j-i+1));
                mp2[str[i]]--;
                if(mp2[str[i]]==0)mp2.erase(str[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends