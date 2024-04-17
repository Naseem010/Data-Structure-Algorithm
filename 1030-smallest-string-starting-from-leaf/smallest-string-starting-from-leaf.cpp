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
     string smallestFromLeaf(TreeNode* root) {
        string current;
        string answer = "~";  // Using '~' because it's lexicographically after 'z'
        dfs(root, current, answer);
        return answer;
    }

    void dfs(TreeNode* node, string& current, string& answer) {
        if (!node) return;

        // Convert integer to character assuming it represents 'a' to 'z'
        current.push_back('a' + node->val);

        // If it's a leaf node
        if (!node->left && !node->right) {
            string leafStr = current;
            std::reverse(leafStr.begin(), leafStr.end());
            if (leafStr < answer) {
                answer = leafStr;
            }
        }

        dfs(node->left, current, answer);
        dfs(node->right, current, answer);

        // Remove the last character added before going back up the recursive call stack
        current.pop_back();
    }

};