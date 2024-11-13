class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        long long cnt=0;
        for(int i=0;i<nums.size();i++){
            int lx=lower-nums[i];
            int ux=upper-nums[i];
           int lower=lower_bound(nums.begin(),nums.end(),lx)-nums.begin();
           int higher=upper_bound(nums.begin(),nums.end(),ux)-nums.begin();
            cnt+=higher-lower;
            if (nums[i] >= lx && nums[i] <= ux) {
            cnt--;
        }
        }
        return cnt/2;
    }
};