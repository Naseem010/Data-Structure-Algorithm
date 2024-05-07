/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        
//         ListNode* curr=head;
//         int num=0;
//         while(curr!=nullptr){
//             int currnum=curr->val;
//             num=(num*10)+(currnum%10);
//             curr=curr->next;
//         }
//         num=2*num;
//         ListNode* nxt=new ListNode(0);
//         ListNode* temp=nxt;
//         bool flag=true;
//         while(num>0){
//             int x=num%10;
//             num=num/10;
//             ListNode* newnode=new ListNode(x);
//             newnode->next=temp;
//             if(flag){
//                 newnode->next=NULL;
//                 flag=false;
//             }
//             temp=newnode;
//         }
// return temp;
 ListNode* curr=head;
 ListNode* prev=NULL;
 while(curr!=NULL){
    ListNode* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
 }
 
 head=prev;
 curr=prev;
//  while(curr!=NULL){
//     cout<<curr->val;
//     curr=curr->next;
//  }

 int carry=0;
 while(curr!=NULL){
    int newcurr=curr->val*2;
    if(carry!=0){
        newcurr+=carry;
        carry=0;
    }
    if(newcurr>4){
        carry=newcurr/10;
    }
    curr->val=newcurr%10;
    prev=curr;
    curr=curr->next;
 }
 if(carry!=0){
    ListNode* newnode=new ListNode(carry);
    prev->next=newnode;
    newnode->next=NULL;
 }
curr=head;
prev=NULL;
while(curr!=NULL){
    ListNode* temp=curr->next;
    curr->next=prev;
    prev=curr;
    curr=temp;
 }
 return prev;
    }
};