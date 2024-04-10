class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>result(n);
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(i);
        }
        sort(deck.begin(),deck.end());
        for(int card:deck){
            int idx=q.front();
            result[idx]=card;
            q.pop();
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};