class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        int n=classes.size();
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++){
            double change=((double)(classes[i][0]+1)/(classes[i][1]+1))-((double)(classes[i][0])/(classes[i][1]));
            pq.push({change,i});
        }
        double sum=0;
        
       while(extraStudents--){
            pair<double,int>p=pq.top();pq.pop();
            int i=p.second;
            classes[i][0]++;
            classes[i][1]++;
            double change=((double)(classes[i][0]+1)/(classes[i][1]+1)-(classes[i][0])/(double)(classes[i][1]));
            pq.push({change,i});
        }
        while(!pq.empty()){
            pair<double,int>p=pq.top();pq.pop();
            int i=p.second;
            sum+=(double)classes[i][0]/classes[i][1];
        }
        return sum/(double)classes.size();
    }
};