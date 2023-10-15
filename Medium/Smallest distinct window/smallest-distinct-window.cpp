//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str)
    {
        // Your code goes here 
        unordered_map<char,int>map,map1;
        for(auto it:str)map[it]++;
        int i=0,j=0,ans=INT_MAX;
        
        while(j<str.size())
        {
            map1[str[j]]++;
            
            while(map1.size()==map.size())
            {
                ans=min(ans,j-i+1);
                map1[str[i]]--;
                if(map1[str[i]]==0)map1.erase(str[i]);
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