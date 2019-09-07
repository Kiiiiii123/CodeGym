'''
题目：输入一个链表，输出该链表中倒数第k个结点。
'''

'''
方法一：遍历一次链表获得链表长度，再次遍历链表，至n-k+1出输出
运行时间：23ms
占用内存：5728k
'''

#class ListNode:
#     def __init__(self, x):
#            self.val = x  
#            self.next = None

class Solution:
    def FindKthToTail(self, head, k):
        # write code here
        if head==None or k<=0:
            return None
        p=head
        n=1
        while p.next!=None:
            p=p.next
            n=n+1
        if k>n:
            return None
        for i in range(n-k):
            head=head.next
        return head












