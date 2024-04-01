class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int maxi=0;
        int r=0,l=0;
        int n=nums.size();
        while(r<n){
                mp[nums[r]]++;
            
                while(mp[nums[r]]>k){
                    mp[nums[l]]--;
                    l++;
                    
                
            }
            maxi=max(maxi,(r-l+1));
            r++;
        }
        return maxi;
    }
};