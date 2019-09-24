'''
题目：输入一颗二叉树的根节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。(注意: 在返回值的list中，数组长度大的数组靠前)     
'''

'''
方法： 用前序遍历的方式访问二叉树的节点（先根节点，后左右子节点），当访问到一个节点时，将该节点加到路径中，并累加节点的值，直到访问到符合要求的节点或者访问到叶节点，注意最后需要排序，使用python高阶函数sorted()。
运行时间：24ms
占用内存：5728k
'''
