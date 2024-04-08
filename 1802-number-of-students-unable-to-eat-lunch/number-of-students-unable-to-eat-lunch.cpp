class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int>vect(2,0);
        for(int it:students){
           vect[it]++;
        }
        int remaining=students.size();
        for(int it:sandwiches){
            if(vect[it]==0)break;
            if(remaining==0)break;
            vect[it]--;
            remaining--;
        }
        return remaining;
    }
};