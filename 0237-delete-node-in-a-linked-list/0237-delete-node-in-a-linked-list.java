/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode prev=null;
        while(node.next!=null){
            ListNode fut=node.next;
            int value=node.val;
            node.val=fut.val;
            fut.val=value;
            prev=node;
            node=node.next;
        }
        prev.next=null;
    }
}