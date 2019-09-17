'''
题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。          
'''

'''
方法：使用辅助列表，本质上是将二叉树的节点值按顺序放到列表中
运行时间：24ms
占用内存：5732k
'''

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回从上到下每个节点值列表，例：[1,2,3]
    def PrintFromTopToBottom(self, root):
        # write code here
        queue=[]
        result=[]
        if not root:
            return result
        queue.append(root)
        while queue:
            Node=queue.pop(0)
            result.append(Node.val)
            if Node.left:
                queue.append(Node.left)
            if Node.right:
                queue.append(Node.right)
        return result
