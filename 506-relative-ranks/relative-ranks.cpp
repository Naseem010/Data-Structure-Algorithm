class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string>ans;
        vector<int>temp;
        for(auto it:score){
            temp.push_back(it);
        }
        sort(temp.begin(),temp.end());
        unordered_map<int,int>mp;
        int j=1;
        for(int i=temp.size()-1;i>=0;i--){
            mp[temp[i]]=j;
            j++;
        }
        for(int i=0;i<score.size();i++){
        if(mp[score[i]]!=1 && mp[score[i]]!=2 && mp[score[i]]!=3){
                ans.push_back(to_string(mp[score[i]]));
            }else if(mp[score[i]]==1 ){
                ans.push_back("Gold Medal");
            }
            else if(mp[score[i]]==2 ){
                ans.push_back("Silver Medal");
            }
            else if(mp[score[i]]==3 ){
                ans.push_back("Bronze Medal");
            }
        }
        return ans;
    }
};