//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    string lookandsay(int n) {
        // code here
      /*  string temp="1";
       
        while(n--){
             string ans="";
        int count=1;
        for(int i=0;i<temp.size();i++){
            if(temp[i]==temp[i+1]){
                count++;
            }else{
                string cntstr=to_string(count);
                ans+=cntstr;
                ans+=temp[i];
                count=1;
                if(i=temp.size()-1){
                    // temp="";
                    temp=ans;
                    
                    break;
                }
                
            }
        }
        }
        return temp;*/
            string ans = "1";
        string temp;
        n--;
        while(n--)
        {
            int count = 1;
            for(int i = 1 ; i < ans.size(); i++)
            {
                if(ans[i] == ans[i-1]) count++;
                else
                {
                    temp += to_string(count) + ans[i-1];
                    count = 1;
                }
            }
            temp += to_string(count) + ans[ans.size()-1];
            ans = temp;
            temp = "";
        }
        return ans;
    }   
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution obj;
        cout<<obj.lookandsay(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends