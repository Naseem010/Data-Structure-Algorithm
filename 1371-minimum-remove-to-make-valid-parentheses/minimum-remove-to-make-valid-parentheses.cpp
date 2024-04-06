class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<char>vect(s.begin(),s.end());
        int cntopen=0;
        for(int i=0;i<vect.size();i++){
            if(vect[i]=='(')cntopen++;
            else if(vect[i]==')'){
                if(cntopen==0){
                    vect[i]='*';
                }else cntopen--;

            }

        }
        for(int i=vect.size()-1;i>=0;i--){
            if(vect[i]=='(' && cntopen>0){
                cntopen--;
                vect[i]='*';
            }
        }
        string result="";
        for(auto it:vect){
            if(it!='*'){
                result+=it;
            }
        }
        return result;
    }
};