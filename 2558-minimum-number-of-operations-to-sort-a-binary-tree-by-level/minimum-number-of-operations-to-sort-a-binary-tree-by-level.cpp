/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int cnt=0;
        while(!q.empty()){
            int size=q.size();
            vector<int>unsorted;
            while(size--){
                TreeNode* node=q.front();
                q.pop();
                unsorted.push_back(node->val);
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
            }
            vector<int>sorted=unsorted;
            sort(sorted.begin(),sorted.end());
            unordered_map<int,int>mp;
                for(int i=0;i<unsorted.size();i++){
                    mp[unsorted[i]]=i;
                }
                for(int i=0;i<unsorted.size();i++){
                    while(sorted[i]!=unsorted[i]){
                        cnt++;
                        int curr=mp[sorted[i]];
                        mp[unsorted[i]]=curr;
                        swap(unsorted[i],unsorted[curr]);
                    }
                }
                    }
                    return cnt;
    }
};