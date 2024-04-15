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
        if(root==NULL)return 0;
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(root);
        int sum=0;
        while(!q1.empty()){
            TreeNode* node=q1.front();
            q1.pop();
            if(node->left){
                // q1.push(node->left);
                // q2.push(node->left);
                if(node->left->left  &&node->left->right)q1.push(node->left);
                else if(node->left->left){
                    q1.push(node->left);
                }
                else if(node->left->right){
                    q1.push(node->left);
                }
                else{
                    q2.push(node->left);
                }
            }
            if(node->right){
                q1.push(node->right);
            }
        }
        while(!q2.empty()){
            TreeNode* node=q2.front();
            q2.pop();
            sum+=node->val;
        }
        return sum;
    }
};