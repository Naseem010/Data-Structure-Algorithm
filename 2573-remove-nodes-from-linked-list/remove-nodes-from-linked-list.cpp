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
    ListNode* removeNodes(ListNode* head) {
        // stack<ListNode*>st;
        // ListNode* curr=head;
        // ListNode* prev=nullptr;
        // while(curr!=nullptr){
        //     ListNode* temp=curr->next;
        //     if(st.empty()){
        //         st.push(curr);
        //     }else{
        //         while(!st.empty()){
        //             ListNode* Top=st.top();
        //             if(curr->val < Top->val){
        //                 st.push(curr);
        //                 break;
        //             }else if(curr->val > Top->val){
        //                 st.pop();
        //             }
        //         }
        //         if(st.empty()){
        //         st.push(curr);
        //         }
        //     }
        //     curr=temp;
        // }
          ListNode* curr = head;
        stack<ListNode*> st;
        
        while (curr != nullptr) {
            while (!st.empty() && st.top()->val < curr->val) {
                st.pop();
            }
            st.push(curr);
            curr = curr->next;
        }
        ListNode* nxt = nullptr;
        while (!st.empty()) {
            curr = st.top();
            st.pop();
            curr->next = nxt;
            nxt = curr;
        }
        return nxt;
    }
};