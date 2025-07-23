/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        int length1=0,length2=0;
        ListNode n1=headA;
        ListNode n2=headB;
        while(n1!=null){
            length1++;
            n1=n1.next;
        }
        while(n2!=null){
            length2++;
            n2=n2.next;
        }
        if(length1>length2){
            int n=length1-length2;
            while(n!=0){
                headA=headA.next;
                n--;
            }
        }
         if(length1<length2){
            int n=length2-length1;
            while(n!=0){
                headB=headB.next;
                n--;
            }
        }
        if(headA==headB)return headA;
        while(headA!=headB){
            headA=headA.next;
            headB=headB.next;
            if(headA==headB)return headA;
        }
return null;
    }
}