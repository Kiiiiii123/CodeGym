'''
题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）
'''

'''
方法：在树A中查找和树B根节点一致的值，然后判断树A中以该节点为根节点的子树，是不是和树B有相同的结构。可以通过递归实现。
运行时间：27ms
占用内存：5864k
'''

class Solution:
    def HasSubtree(self, pRoot1, pRoot2):
        # write code here
        if pRoot1==None or pRoot2==None:
            return False
        result=False
        if pRoot1.val==pRoot2.val:
            result=self.isSubtree(pRoot1,pRoot2)
        if result==False:
            result=self.HasSubtree(pRoot1.left,pRoot2) or self.HasSubtree(pRoot1.right,pRoot2)
        return result
        
    def isSubtree(self,root1,root2):
        if root2==None:
            return True
        if root1==None:
            return False
        if root1.val==root2.val:
            return self.isSubtree(root1.left,root2.left) and self.isSubtree(root1.right,root2.right)
        return False
