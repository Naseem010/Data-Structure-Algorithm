//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    struct node *reverseIt (struct node *head, int k)
    { 
        // Complete this method
        if(head==NULL || head->next==NULL){
            return head;
        }
        node *curr=head;
        node *temp=curr->next;
        node *prev=NULL;
        int cnt=1;
        while(curr!=NULL && cnt<k+1 ){
            curr->next=prev;
            prev=curr;
            curr=temp;
            if(curr!=NULL){
                
            temp=curr->next;
            }
            cnt++;
        }
        if(curr!=NULL){
            head->next=reverseIt(curr,k);
        }
        return prev;
//          if(head==NULL || head->next==NULL){
//             return head;
//         }
//          struct node* initial=head;
//         struct node* prev=head;

//     struct node* temp=head->next;
//     struct node* after=NULL;
//     initial->next=NULL;
//     int count=1;
//     while(temp!=NULL && count<k){
//         after=temp->next;
//         temp->next=prev;
//         prev=temp;
//         temp=after;
//         count++;
        
//     }
// if(temp!=NULL){
//     head->next=reverseIt(temp,k);
// }
// return prev;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverseIt(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends