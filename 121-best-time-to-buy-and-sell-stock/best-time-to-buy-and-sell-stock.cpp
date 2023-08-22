class Solution {
public:
    int maxProfit(vector<int>& prices) {
              int buy=prices[0];
        int profit=0;
        int sumProfit=0;
        int N=prices.size();
        for(int i=1;i<N;i++){
            if(buy>prices[i]){
                buy=prices[i];
            }else if((prices[i]-buy)>profit){
                profit=prices[i]-buy;
            }
        }
      
        return profit;
    }
};