//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

// Should return true if tree is Sum Tree, else false
class Solution {
  public:
  int sum(Node* que){
        int sum=0;
        queue<Node*> q2;
        q2.push(que);
        while(!q2.empty()){
            int size=q2.size();
            while(size--){
                auto itr=q2.front();
                sum+=itr->data;
                q2.pop();
                if(itr->left) q2.push(itr->left);
                if(itr->right) q2.push(itr->right);
            }
        }
        return sum-que->data;
    }
    bool isSumTree(Node* root) {
        // Your code here
        // queue<Node*>q;
        // q.push(root);
        // Node* left1=new Node();
        // Node* right1=new Node();
        // while(!q.empty()){
            
        //     Node* node=q.front();
        //     q.pop();
        //     if(node->left){
        //         left1=node->left;
        //         q.push(left1);
        //     }
        //      if(node->right){
        //         right1=node->right;
        //         q.push(right1);
        //     }
        //     if(node->data != ((right1->data) + (left1->data))){
        //         return false;
        //     }
            
        // }
        // return true;
           queue<Node*> q1;
        q1.push(root);
        while(!q1.empty()){
            int size=q1.size();
            while(size--){
                auto q=q1.front();
                q1.pop();
                if(q->left and q->right){
                    if(sum(q)!=q->data) return false;
                    q1.push(q->left);
                    q1.push(q->right);
                }
                else if(q->left or q->right) return false;
        }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;

        getline(cin, s);

        Node* root = buildTree(s);
        Solution ob;
        if (ob.isSumTree(root))
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 1;
}
// } Driver Code Ends