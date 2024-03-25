class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // unordered_map<int,int>mp;
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // vector<int>ans;
        // for(auto it:mp){
        //     if(it.second>1){
        //         ans.push_back(it.first);
        //     }
        // }
        // return ans;
       vector<int>result;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int num =abs(nums[i]);
            int idx = num - 1;
            if(nums[idx] < 0)
                result.push_back(num);
            
            nums[idx] *= -1;
        }
        return result;
  
    }
};