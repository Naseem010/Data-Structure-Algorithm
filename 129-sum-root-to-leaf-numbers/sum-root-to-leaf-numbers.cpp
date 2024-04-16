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
    void solve(TreeNode*root,vector<vector<int>>&ans,vector<int>&res){
  
     
     if(root==NULL){
        return;
     }  

    
    res.push_back(root->val);

       // Check if we're at a leaf node
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(res);
        } else {
            // Continue to explore left and right children
            if (root->left) {
                solve(root->left, ans, res);
            }
            if (root->right) {
                solve(root->right, ans, res);
            }
        }

    res.pop_back();


    }
    int sumNumbers(TreeNode* root) {
        vector<int>res;
        vector<vector<int>>ans;
        solve(root,ans,res);
        for(auto it:ans){
            for(auto i:it){
                cout<<i;
            }
            cout<<endl;
        }
        int wow=0;
        vector<int>final;
        for(auto i:ans){
            wow=0;
            for(auto it:i){
              wow=wow*10+it;
            }

            final.push_back(wow);
        }

        int result=0;
        for(auto i:final){
            result+=i;
        }

        return result;
    }
    
};