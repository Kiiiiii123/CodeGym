'''
题目：输入一个链表，反转链表后，输出新链表的表头。
'''

'''
方法：迭代法
运行时间：26ms
占用内存：5844k
'''

# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # 返回ListNode
    def ReverseList(self, pHead):
        # write code here
        if not pHead or not pHead.next:
            return pHead
        last=None
        while pHead:
            temp=pHead.next
            pHead.next=last
            last=pHead
            pHead=temp
        return last
