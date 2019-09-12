'''
题目：操作给定的二叉树，将其变换为源二叉树的镜像。
输入描述：
二叉树的镜像定义：源二叉树 
    	    8
    	   /  \
    	  6   10
    	 / \  / \
    	5  7 9 11
    	镜像二叉树
    	    8
    	   /  \
    	  10   6
    	 / \  / \
    	11 9 7  5                                 
'''

'''
方法：递归交换树的左右节点即可。
运行时间：30ms
占用内存：6380k
'''

# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    # 返回镜像树的根节点
    def Mirror(self, root):
        # write code here
        if root==None or (root.left==None and root.right==None):
            return
        root.left,root.right=root.right,root.left
        self.Mirror(root.left)
        self.Mirror(root.right)
        return root
