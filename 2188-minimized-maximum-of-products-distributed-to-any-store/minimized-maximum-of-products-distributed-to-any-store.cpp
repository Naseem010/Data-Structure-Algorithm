class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        sort(quantities.begin(),quantities.end());
        int m=quantities[quantities.size()-1];
        int low=1;
        int high=m;
        int index=INT_MAX;
        if(n==1){
            return m;
        }
        while(low<=high){

        int mid=(low+high)/2;
        // for(int i=1;i<=m;i++){
            long long cnt=0;
            for(int j=0;j<quantities.size();j++){
            cnt+=quantities[j]/mid;
            if(quantities[j]%mid!=0){
            cnt+=1;
            }
            }
            if(cnt<=n){
                index=min(mid,index);
                high=mid-1;
            }else{
                low=mid+1;
            }

        // }
        }
        return index;
    }
};