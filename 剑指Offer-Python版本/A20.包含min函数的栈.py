'''
题目：定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数（时间复杂度应为O（1））。               
'''

'''
方法：建立一个辅助栈，每次都把最小值压入辅助栈，这样辅助栈的栈顶一直是最小元素。当数据栈中，最小值被弹出时，同时弹出辅助栈的栈顶元素。
运行时间：26ms
占用内存：5728k
'''

class Solution:
    #初始化
    def __init__(self):
        self.stack=[]
        #建立辅助栈
        self.min_stack=[]
    def push(self, node):
        # write code here
        self.stack.append(node)
        if not self.min_stack or node <= self.min_stack[-1]:
            self.min_stack.append(node)
    def pop(self):
        # write code here
        #这里需要注意顺序
        if self.stack[-1]==self.min_stack[-1]:
            self.min_stack.pop()
        self.stack.pop()
    def top(self):
        # write code here
        return self.stack[-1]
    def min(self):
        # write code here
        return self.min_stack[-1]
