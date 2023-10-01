class Solution {
public:
    int minOperations(vector<int>& nums) {
        if(nums.size()<2){
            return -1;
        }
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int count=0;
        for(auto it:mp){
            int k=it.second;
            if(k==1){
                return -1;
            }
            if(k%3==0){
                count+=(k/3);
            }else{
                count+=(k/3)+1;
            }
        }
        return count;
        
    }
};