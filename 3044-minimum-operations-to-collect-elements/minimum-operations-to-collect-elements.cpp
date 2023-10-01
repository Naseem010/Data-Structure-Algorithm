class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>vec(k+1,-1);
        int count=0;
        int temp=0;
        for(int i=nums.size()-1;i>=0;i--){
            if(temp==k){
                return count;
            }
         else if(nums[i]<=k){
             if(vec[nums[i]]==-1){
                temp++;
                vec[nums[i]]=1;
             }
              
          }
          count++;
        }
        return count;
    }
};