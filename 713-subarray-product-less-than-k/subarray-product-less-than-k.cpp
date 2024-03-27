class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         if (k == 0)
            return 0;
        int n = nums.size(), product = 1, cnt {};
        int l = 0, r = 0;
        while(r < n)
        {
            product *= nums[r++];
            while(l < r && product >= k)
                product /= nums[l++];
            
            cnt += (r - l);
        }
        return cnt;
    }
};