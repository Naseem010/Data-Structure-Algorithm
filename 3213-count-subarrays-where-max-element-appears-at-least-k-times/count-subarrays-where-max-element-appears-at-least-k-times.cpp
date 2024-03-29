class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int>st;
                int n=nums.size();
        // for(int i=0;i<nums.size();i++){
        //     st[nums[i]]++;
        // }
        // int maxe;
        // int max=INT_MIN;
        // for(auto it:st){
        //     if(it.second>max){
        //         maxe=it.first;
        //         max=it.second;
        //     }
        // }
                int maxe=*max_element(nums.begin(), nums.end());
        cout<<maxe<<endl;
         long long ans=0;
        
        int count=0; // keep track of count of maxElement in [i,j]
        int i=0, j=0;
        while(j<n){
            count += (nums[j] == maxe);
            
            while(i<=j && count>=k){
                ans += (n-j);
                
                count -= (nums[i] == maxe); // shrink window
                i++;
            }
            j++;
        }
        
        return ans;
    }
};