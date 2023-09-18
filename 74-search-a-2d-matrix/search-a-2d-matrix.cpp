class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int left=0;
        int right=col-1;
        int top=0;
        int bottom=row-1;
        while(top<=bottom){
            if(matrix[top][right]>=target){
                for(int i=left;i<=right;i++){
                    if(matrix[top][i]==target)return true;
                  
                }
            }
            top++;
        }
return false;
    }
};