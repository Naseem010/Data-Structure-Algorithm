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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // queue<TreeNode*>q;
        // q.push(root);
        // int d=1;
        // while(!q.empty()){
        //     d++;
        //     TreeNode* prev=q.front();
        //     q.pop();
        //     if(d==depth){
        //         prev->left=new TreeNode(val);
        //         prev->right=new TreeNode(val);
        //         prev->left->left=q.front();
        //         q.pop();
        //         prev->right->right=q.front();
        //         q.pop();
                
        //     }
        //     if(prev->left)q.push(prev->left);
        //     if(prev->right)q.push(prev->right);
        // }
        // return root;
         if (depth == 1) {
        TreeNode* newRoot = new TreeNode(val); // Create a new root
        newRoot->left = root;                 // Set old root as left child
        return newRoot;                       // Return new root
    }

    queue<TreeNode*> q;
    q.push(root);
    int currentDepth = 1;                      // Start from depth 1 (root level)

    // Process each level until the level before the target depth
    while (!q.empty()) {
        int levelSize = q.size();
        if (currentDepth == depth - 1) {
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();

                // Insert new nodes
                TreeNode* newLeft = new TreeNode(val);
                TreeNode* newRight = new TreeNode(val);
                newLeft->left = node->left;   // Connect old left to new left's left
                newRight->right = node->right; // Connect old right to new right's right
                node->left = newLeft;         // Update current node's left to new left
                node->right = newRight;       // Update current node's right to new right
            }
            break;
        } else {
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            currentDepth++; // Increment depth only after processing all nodes at the current level
        }
    }
    return root;
    }
};