'''
题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历的结果。如果是则输出Yes,否则输出No。假设输入的数组的任意两个数字都互不相同。       
'''

'''
方法：根据后序遍历的特点，尾元素一定是根节点，同时小于尾元素的值时左子树，大于尾元素的值时右子树。且序列前半部分小于尾元素，后半部分大于尾元素，可以将序列划分为左子树序列和右子树序列，然后递归。注意左子树和右子树为空的情况，此时不进行递归。
运行时间：37ms
占用内存：5856k
'''

class Solution:
    def VerifySquenceOfBST(self, sequence):
        # write code here
        if not sequence:
            return False
        root=sequence[-1]
        length=len(sequence)
        for i in range(length):
            if sequence[i]>root:
                break
        for j in range(i,length):
            if sequence[j]<root:
                return False
        left=True
        if i>0:
            left=self.VerifySquenceOfBST(sequence[:i])
        right=True
        if j <length-1:
            right=self.VerifySquenceOfBST(sequence[i:length-1])
        return left and right
