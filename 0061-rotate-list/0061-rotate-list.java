/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if(head==null||head.next==null||k==0)return head;
        ListNode x=head;
        int len=1;
        while(x.next!=null){
            len++;
            x=x.next;
        }
        x.next=head;
        x=x.next;
        k=k%len;
        for(int i=0;i<len-k-1;i++){
            x=x.next;
        }
        ListNode newHead=x.next;
        x.next=null;
        return newHead;
    }
}