class Solution {
public:
int helper(int n,unordered_map<int,int>&mp){
    if(mp.find(n)!=mp.end()){
        return mp[n];
    }
    int result;
    if(n==0){
result=0;
    }else if(n==1 || n==2){
        result=1;
    }else{
        result=helper(n-1,mp)+helper(n-2,mp)+helper(n-3,mp);
    }
    mp[n]=result;
    return result;

}
    int tribonacci(int n) {
      unordered_map<int,int>mp;
      return helper(n,mp);
    }
};