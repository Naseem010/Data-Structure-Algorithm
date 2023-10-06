//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
  void solve(string &s,int ind,string temp,vector<string>&res,int count,string str){
        if(ind == s.size()){
            if(count==-1 && temp.size()==ind+4){
                temp.pop_back();
                res.push_back(temp);
            }
            return;
        }
        str += s[ind];
        if(str != "" && stoi(str) > 255) return;
        if(str[0]=='0' &&  str.size()>1){
            return;
        }
        solve(s,ind+1,temp,res,count,str);
        solve(s,ind+1,temp+str+'.',res,count-1,"");
    }
    vector<string> genIp(string &s) {
        // Your code here
       vector<string>res;
        string temp;
        solve(s,0,temp,res,3,"");
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends