//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool areAnagrams(string& s1, string& s2) {
        // Your code here
        int n1=s1.size();
        int n2=s2.size();
        if(n1!=n2)return false;
        map<char,int>mp1,mp2;
        for(int i=0;i<n1;i++){
            mp1[s1[i]]++;
        }
        for(int i=0;i<n2;i++){
            mp2[s2[i]]++;
        }
        for(int i=0;i<n1;i++){
            if(mp1[s1[i]]!=mp2[s1[i]])return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.areAnagrams(c, d))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends