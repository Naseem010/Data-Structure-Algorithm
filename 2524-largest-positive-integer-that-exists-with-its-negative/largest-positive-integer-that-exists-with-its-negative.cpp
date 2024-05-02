class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        stack<int>st;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                st.push(nums[i]);
            }
        }
        while(!st.empty()){
            int temp=st.top();
            st.pop();
            for(int i=0;i<nums.size();i++){
                if(-temp==nums[i]){
                    return temp;
                }
            }
        }
        return -1;
    }
};