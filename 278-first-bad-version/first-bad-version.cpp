// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=1;
        int j=n;
        int ans=INT_MAX;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(isBadVersion(mid)){
                j=mid-1;
                ans=min(ans,mid);
            }else{
                i=mid+1;
            }
        }
        return ans;
    }
};