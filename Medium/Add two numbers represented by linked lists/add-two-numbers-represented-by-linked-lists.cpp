//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
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
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        // code here
        first=reverse(first);
        second=reverse(second);
        Node *ans=new Node((first->data+second->data)%10);
        Node *ans1=ans;
        int carry=(first->data+second->data)/10;
        first=first->next;
        second=second->next;
        while(first!=NULL && second!=NULL){
            Node *temp=new Node((first->data+second->data+carry)%10);
            carry=(first->data+second->data+carry)/10;
            ans->next=temp;
            ans=ans->next;
            first=first->next;
            second=second->next;
        }
        while(first!=NULL){
            Node *temp=new Node((first->data+carry)%10);
            carry=(first->data+carry)/10;
            ans->next=temp;
            ans=ans->next;
            first=first->next;
            
        }
        while(second!=NULL){
            Node *temp=new Node((second->data+carry)%10);
            carry=(second->data+carry)/10;
            ans->next=temp;
            ans=ans->next;
            second=second->next;
        }
        if(carry){
             Node *temp=new Node((carry)%10);
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
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends