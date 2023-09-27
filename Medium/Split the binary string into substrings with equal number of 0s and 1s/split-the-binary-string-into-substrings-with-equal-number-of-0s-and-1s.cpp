//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        //Write your code here
        // int n=str.size();
        // if(n%2!=0)return -1;
        // int count0=0;
        // int count1=0;
        // int ans=0;
        // for(int i=0;i<n;i++){
        //     if(count0==count1 && count0!=0){
                
        //         ans++;
        //         count0=0;
        //         count1=0;
        //     }
        //     if(str[i]==0){
        //         count0++;
        //     }else if(str[i]==1){
        //         count1++;
        //     }
        // }
        // return ans;
          int ans=0,zeros=0,ones=0;
        for(int i=0;i<str.size();i++){
            if(str[i]=='0')
            zeros++;
            else if(str[i]=='1'){
                ones++;
                
            }
            if(ones==zeros){
                    ans++;
                    ones=0;zeros=0;
                }
        }
        if(ones!=zeros)return -1;
        return ans;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends