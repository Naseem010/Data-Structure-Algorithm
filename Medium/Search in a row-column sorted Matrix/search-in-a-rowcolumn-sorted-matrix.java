//{ Driver Code Starts
import java.io.*;
import java.util.*;

class GFG{
	public static void main(String args[]) throws IOException { 
		Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t > 0){
       		int rows=sc.nextInt();
       		int columns=sc.nextInt();
			
			int matrix[][]=new int[rows][columns];
          
        	for(int i=0; i<rows;i++){            
            	for(int j=0; j<columns;j++){
                	matrix[i][j]=sc.nextInt();
            	}
         	}
         	int target = sc.nextInt();
         	
			Solution x = new Solution();
			
			if (x.search(matrix, rows, columns, target)) 
				System.out.println(1); 
			else
				System.out.println(0); 
			t--;
		}
	} 
}
// } Driver Code Ends




class Solution 
{ 
    //Function to search a given number in row-column sorted matrix.
	static boolean search(int matrix[][], int n, int m, int x) 
	{  
	    // code here 
	   //  int n=matrix.size();
    //     int m=matrix[0].size();
        // int left=0;
        // int right=col-1;
        // int top=0;
        // int bottom=row-1;
        int row=n-1;
        int col=0;
        while(row>=0 && row<n && col>=0 && col<m){
           if(matrix[row][col]==x)return true;
           else if(x<matrix[row][col]){
               row--;
           }else{
               col++;
           }
        }
return false;
	} 
} 
