//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


// } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    //1) transpose (row->col exchange)
    //2) reverse the row in case of clockwise rotation or see the pattern in other case
    
    // for(int i=0;i<=matrix.size()-2;i++){
    //     for(int j=i+1;j<=matrix.size()-1;j++){
    //   swap(matrix[i][j],matrix[j][i]);
    //     }
    // }
    // for(int i=0;i<matrix.size()/2;i++){
    //     swap(matrix[i],matrix[matrix.size()-i-1]);
    // }
       int n = matrix.size();             // gives the no. of rows
     

   // EACH ROW REVERSAL
     for(int i=0; i<n; i++){
         int low = 0, high=n-1;
         
         while(low<high){
             swap(matrix[i][low], matrix[i][high]);
             high--;
             low++;
         }
     }
     

    // TRANSPOSE OF MATRIX
     for(int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
          swap(matrix[i][j], matrix[j][i]);
  
}


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}


// } Driver Code Ends