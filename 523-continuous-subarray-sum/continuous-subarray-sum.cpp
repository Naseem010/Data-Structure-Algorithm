class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // unordered_map<int,int>mp;
        // int sum=0;
        // for(int i=0;i<nums.size();i++){
        //     sum+=nums[i];
        //     int rem=sum%k;
        //     if(rem==0 && i>0)return true;
        //     if(mp.find(rem)!=mp.end() && ((i-mp[rem])>=2)){
        //         return true;
        //     }
        //     else{
        //     mp[rem]=i;
        //     }
        // }
        // return false;
         int n=nums.size();
        unordered_map<int,int>mpp;
        int rem=0,sum=0,len=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            rem=sum%k;
            if(i!=0 && rem==0){
                return true;
            }
            if(mpp.find(rem)!=mpp.end()){
                len=i-mpp[rem];
                if(len>=2){
                    return true;
                }
            }else{
                mpp[rem]=i;
            }
        }
        return false;
    }
};