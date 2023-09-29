//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            //code here.
            int index=-1;
            int n=txt.size();
            int m=pat.size();
            vector<int>ans;
            int j=0;
            string temp="";
            for(int i=0;i<n;i++){
                if(pat[j]==txt[i]){
                    index=i+1;
                    while(j<m){
                        if(pat[j]!=txt[i]){
                            temp="";
                            j=0;
                            i=index-1;
                            index=-1;
                            break;
                        }
                        temp+=pat[j];
                        j++;
                        i++;
                    }
                    if(temp==pat){
                        ans.push_back(index);
                         temp="";
                         j=0;
                         i=index-1;
                         index=-1;
                    }
                }
            }
            if(ans.size()==0){
            ans.push_back(-1);
            }  
            return ans;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends