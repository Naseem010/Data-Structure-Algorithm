class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0 && mp[arr[i]]>1)return true;
            if(arr[i]%2==0 && arr[i]!=0){
                int k=arr[i]/2;
                if(mp[k]>0)return true;
            }
        }
        return false;
    }
};