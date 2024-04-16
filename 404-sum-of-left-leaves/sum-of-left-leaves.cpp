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
    int sumOfLeftLeaves(TreeNode* root) {
        // if(root==NULL)return 0;
        // queue<TreeNode*>q1;
        // queue<TreeNode*>q2;
        // q1.push(root);
        // int sum=0;
        // while(!q1.empty()){
        //     TreeNode* node=q1.front();
        //     q1.pop();
        //     if(node->left){
        //         // q1.push(node->left);
        //         // q2.push(node->left);
        //         if(node->left->left  &&node->left->right)q1.push(node->left);
        //         else if(node->left->left){
        //             q1.push(node->left);
        //         }
        //         else if(node->left->right){
        //             q1.push(node->left);
        //         }
        //         else{
        //             q2.push(node->left);
        //         }
        //     }
        //     if(node->right){
        //         q1.push(node->right);
        //     }
        // }
        // while(!q2.empty()){
        //     TreeNode* node=q2.front();
        //     q2.pop();
        //     sum+=node->val;
        // }
        // return sum;
        int sum=0;
        if(!root)return sum;
        if(!root->left && !root->right)return sum;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
           pair<TreeNode*,int>temp=q.front();
            if(temp.second==1){
                sum+=temp.first->val;
            }
            q.pop();
            if(temp.first->left){
                if(temp.first->left->left ||temp.first->left->right){
                      q.push({temp.first->left,0});
                }else{
                q.push({temp.first->left,1});
                }
            }
            if(temp.first->right){
               
                q.push({temp.first->right,0});
                
            }

        }
        return sum;
    }
};