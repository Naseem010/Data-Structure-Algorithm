class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>st;
        int i=0,j=0;
        
        int n1=nums1.size();
        int n2=nums2.size();
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        while(i<n1 && j<n2){
            if(nums1[i]>nums2[j]){
                j++;
            }else if(nums1[i]<nums2[j]){
                i++;
            }else{
                st.insert(nums1[i]);
                i++;
                j++;
            }
        }
vector<int>ans;
for(auto it:st){
    ans.push_back(it);
}
return ans;
    }
};