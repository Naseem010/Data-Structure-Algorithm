/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr=node;
        ListNode* prev=NULL;
        while(curr->next!=NULL){
            ListNode* temp=curr->next;
            int currv=curr->val;
            curr->val=temp->val;
            temp->val=currv;
            prev=curr;
            curr=temp;
        }
        prev->next=NULL;
    }
};