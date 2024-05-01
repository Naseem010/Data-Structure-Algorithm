class Solution {
public:
    string reversePrefix(string word, char ch) {
        string temp="";
        bool flag=true;
        int i;
        for(i=0;i<word.size();i++){
            if(word[i]==ch){
                temp+=word[i];
                flag=false;
                break;
            }
            temp+=word[i];
        }
        cout<<temp;
        if(flag){
            return word;
        }
        if(!flag){
        reverse(temp.begin(),temp.end());
        }
        for(int j=i+1;j<word.size();j++){
            temp+=word[j];
        }
        return temp;
    }
};