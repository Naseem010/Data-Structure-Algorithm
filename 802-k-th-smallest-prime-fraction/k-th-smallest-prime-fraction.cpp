class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // priority_queue<pair<pair<int,int>,int>>pq;
    //     priority_queue<pair<double,pair<int,int>>,vector<pair<double, pair<int, int>>>, greater<>>pq;
    //     int n=arr.size();
    //     for(int j=n-1;j>=1;j--){
    //         for(int i=0;i<j;i++){
    //             double fraction=(arr[i]/arr[j])*100;
    //             pq.push({fraction,{arr[i],arr[j]}});
    //         }
    //     }
    //     int pqsize=pq.size();
    //     int temp=pqsize - k;
    //     cout<<temp;
    //    for(int i=0;i<temp-1;i++){
    //     pq.pop();
    //    }
    //     vector<int>ans;
    //     ans.push_back(pq.top().second.first);
    //     ans.push_back(pq.top().second.second);
    // return ans;
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<>> minHeap;
        int N = arr.size();
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                minHeap.push({(double)arr[i] / arr[j], {arr[i], arr[j]}});
            }
        }
        
        pair<int, int> result;
        for (int i = 0; i < k; ++i) {
            result = minHeap.top().second;
            minHeap.pop();
        }
        
        return {result.first, result.second};
    }
};