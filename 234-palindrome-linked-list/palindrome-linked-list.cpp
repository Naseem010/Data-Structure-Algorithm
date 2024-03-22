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
string reverse(string st){
    string temp;
    for(int i=st.size()-1;i>=0;i--){
        temp+=st[i];
    }
    return temp;
}
    bool isPalindrome(ListNode* head) {
        ListNode *temp=head;
        string st;
        while(temp!=NULL){
            st+=temp->val;
            temp=temp->next;
        }
        string st2=reverse(st);
        if(st==st2)return true;
        return false;
    }
};