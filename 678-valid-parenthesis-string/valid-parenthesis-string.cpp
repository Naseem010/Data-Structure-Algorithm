class Solution {
public:
    bool checkValidString(string s) {
        int low=0,high=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                low++;
                high++;
            }
            else if(s[i]=='*'){
                if(low!=0)low--;
                high++;
            }else if(s[i]==')'){
                if(low!=0)low--;
                if(high==0)return false;
                else high--;
            }
        }
        if(low!=0)return false;
        if(high<0)return false;
        return true;
    }
};