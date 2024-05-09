class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long sum=0;
        sort(happiness.begin(),happiness.end(), greater<int>());
        int turns=0;
        for(int i=0;i<k;i++){
            sum+=max((happiness[i]-turns),0);
            turns++;
        }
        return sum;
    }
};