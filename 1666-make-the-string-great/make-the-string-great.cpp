class Solution {
public:
    string makeGood(string s) {
           stack<char>st;
        string ans="";
        for(int i=0;i<s.size();i++){
            if(!st.empty() && ((st.top()-'a'==s[i]-'A') ||(st.top()-'A'==s[i]-'a'))){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        while(!st.empty()){
ans+=st.top();
st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};