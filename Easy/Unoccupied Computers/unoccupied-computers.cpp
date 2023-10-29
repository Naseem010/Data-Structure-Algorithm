//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int n, string s) {
        // code here
         unordered_map<char,int> mp;
       
       int count=0;
       int ans = 0;
       set<char> st;
       for(int i=0; i<s.length(); i++){
           if (mp.find(s[i]) == mp.end()){
               count++;
               if(count>n && st.find(s[i])==st.end()){
                   st.insert(s[i]);
                   ans++;
                   count--;
               }
                   
               mp[s[i]]++;
               
           }
           
           else if (mp.find(s[i])!=mp.end() && st.find(s[i])==st.end()){
               count--;
               mp.erase(s[i]);
           }
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        cin.ignore();
        string s; 
        getline(cin,s);
        
        Solution obj;
        int res = obj.solve(n, s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends