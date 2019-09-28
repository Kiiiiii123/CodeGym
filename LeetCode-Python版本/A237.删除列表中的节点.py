'''
题目：请编写一个函数，使其可以删除某个链表中给定的（非末尾）节点，你将只被给定要求被删除的节点。
示例：输入: head = [4,5,1,9], node = 5 输出: [4,1,9] 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
说明:
   链表至少包含两个节点。
   链表中所有节点的值都是唯一的。
   给定的节点为非末尾节点并且一定是链表中的一个有效节点。
   不要从你的函数中返回任何结果。
'''

'''
方法：直接对链表进行修改，考察链表数据结构的删除链表节点部分
执行用时：52ms
内存消耗：14.1MB
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val=node.next.val
        node.next=node.next.next
