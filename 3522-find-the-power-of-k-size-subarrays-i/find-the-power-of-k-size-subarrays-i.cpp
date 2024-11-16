class Solution {
public:
bool sorted(int i,int j,vector<int>arr){
    int cnt=0;
    for(int k=i+1;k<=j;k++){
        if(arr[k]!=arr[k-1]+1){
            return false;
        }
        if(arr[k]==arr[k-1]){
            cnt++;
        }
    }
    if(cnt==j-i)return false;
    return true;
}
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int>ans;
        int n=nums.size();
        int i=0;
        int j=k-1;
        if(k==1){
            // ans.push_back(nums[0]);
            return nums;
        }
        while(j<n){
            if(sorted(i,j,nums)){
                ans.push_back(nums[j]);

            }else{
                ans.push_back(-1);
            }
            i++;
            j++;
        }
        return ans;
    }
};