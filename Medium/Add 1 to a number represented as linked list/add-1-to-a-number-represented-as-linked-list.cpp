//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node *reverse(Node*root)
    {
        Node*temp=root;
        Node*prev=NULL;
        Node*cur=root;
        while(cur)
        {
            Node*nexti=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nexti;
        }
        return prev;
    }
    
    Node* addOne(Node *head)
    {
        // Your Code here
        // return head of list after adding one
        int carry=1;
        Node *node=reverse(head);
        Node *ans=new Node((node->data+carry)%10);
        Node *ans1=ans;
         carry=(node->data+carry)/10;
        node=node->next;
        while(node){
            Node *temp=new Node((node->data+carry)%10);
            ans->next=temp;
            ans=ans->next;
              carry=(node->data+carry)/10;
             node=node->next;
        }
        if(carry){
            Node *temp=new Node(carry);
            ans->next=temp;
            ans=ans->next;
        }
        ans=reverse(ans1);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends