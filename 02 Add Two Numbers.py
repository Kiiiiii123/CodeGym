#2. Add Two Numbers
#   You are given two non-empty linked lists representing two non-negative integers. 
#   The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
#   You may assume the two numbers do not contain any leading zero, except the number 0 itself.
#   Examples:
#       Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
#       Output: 7 -> 0 -> 8
#       Explanation: 342 + 465 = 807.# Definition for singly-linked list.

class ListNode:
     def __init__(self, x):
         self.val = x
         self.next = None

class Solution:
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        SumNode=ListNode(0)
        TempNode=SumNode
        Sum=0
        while l1 or l2 or Sum:
            if l1:
                Sum+=l1.val
                l1=l1.next
            if l2:
                Sum+=l2.val
                l2=l2.next
            Sum,val=divmod(Sum,10)
            TempNode.next=ListNode(val)
            TempNode=TempNode.next
        return SumNode.next
#解题思路：创建返回节点以及临时节点，临时节点用于往后接入更多的节点，，注意l1、l2节点为空时仍需要考虑Sum的值来决定是否再while一次，因为有可能需要再进一位