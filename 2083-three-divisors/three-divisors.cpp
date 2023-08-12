class Solution {
public:
    bool isThree(int n) {
        int count=0;
        if(n<=3)return false;
        for(int i=1;i<=n/2;i++){
            if(n%i==0){
                count++;
            }
        }
        if(count==2)return true;
        return false;
    }
};