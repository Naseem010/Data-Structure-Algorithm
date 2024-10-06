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
TreeNode* makeTree(vector<int> preorder,vector<int> inorder,int start,int end,int& preindex){
    if(start>end)return NULL;
    TreeNode* newnode=new TreeNode(preorder[preindex++]);
    if(start==end)return newnode;
    int inIndex=findIndex(newnode->val,inorder,start,end);
    newnode->left=makeTree(preorder,inorder,start,inIndex-1,preindex);
    newnode->right=makeTree(preorder,inorder,inIndex+1,end,preindex);
    return newnode;
}
int findIndex(int key,vector<int>inorder,int start,int end){
    for(int i=start;i<=end;i++){
        if(inorder[i]==key){
            return i;
        }
    }
    return 0;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int>inorder;
        for(int i=0;i<preorder.size();i++){
            inorder.push_back(preorder[i]);
        }
        sort(inorder.begin(),inorder.end());
        int start=0;
        int end=preorder.size()-1;
        int preindex=0;
        return makeTree(preorder,inorder,start,end,preindex);
    }
};