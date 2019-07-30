/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
//神奇的预先指针
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode pre=new ListNode(0);
        ListNode cur=pre;
        int carry=0;
        
        while(l1!=null||l2!=null)
        {
            int x=(l1==null)?0:l1.val;
            int y=(l2==null)?0:l2.val;
            int sum=x+y+carry;
            
            carry=sum/10;
            sum=sum%10;
            cur.next=new ListNode(sum);
            
            cur=cur.next;
            if(l1!=null)
            {
                l1=l1.next;
            }
            if(l2!=null)
            {
                l2=l2.next;
            }
        }
        if(carry==1)
        {
            cur.next=new ListNode(carry);
        }
        return pre.next;
    }
}
