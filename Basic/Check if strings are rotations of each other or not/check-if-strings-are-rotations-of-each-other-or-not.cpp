//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        if(s1.length()!=s2.length())
            return 0;
        queue<char>Q1;
        for(int i=0;i<s1.length();i++){
            Q1.push(s1[i]);
        }
        queue<char>Q2;
        for(int i=0;i<s2.length();i++){
            Q2.push(s2[i]);
        }
        int l=s2.length();
        while(l--){
            char ch=Q2.front();
            Q2.pop();
            Q2.push(ch);
            if(Q1==Q2)
                return 1;
            
        }
        return 0;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends