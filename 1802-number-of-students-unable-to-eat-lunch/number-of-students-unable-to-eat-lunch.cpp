class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        stack<int>st;
        queue<int>q;
        for(int i=sandwiches.size()-1;i>=0;i--){
            st.push(sandwiches[i]);
        }
        for(int i=0;i<students.size();i++){
            q.push(students[i]);
        }
        int cnt=0;
        while(cnt<q.size() && !q.empty() && !st.empty()){
            int bacche=q.front();
            int bread=st.top();
            if(bacche==bread){
                q.pop();
                st.pop();
                cnt=0;
            }else if(bacche!=bread){
                q.pop();
                q.push(bacche);
                cnt++;
            }
        }
        return q.size();
    }
};