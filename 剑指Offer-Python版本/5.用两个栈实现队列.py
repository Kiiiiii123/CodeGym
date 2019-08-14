'''
题目：用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
'''

'''
方法：两个栈stack1和stack2， push的时候直接push进stack1，pop时需要判断stack1和stack2中的情况。如果stack2不为空的话，直接从stack2中pop，如果stack2为空，把stack1中的值push到stack2中，然后再pop stack2中的值。
运行时间：25ms
占用内存：5860k
'''

class Solution:
    def __init__(self):
        self.stack1=[]
        self.stack2=[]
        
    def push(self, node):
        # write code here
        #列表的append操作
        self.stack1.append(node)
        
    def pop(self):
        # return xx
        if not self.stack1 and not self.stack2:
            return
        if self.stack2:
            #列表的pop操作，默认弹出最后一个值
            return self.stack2.pop()
        while self.stack1:
            self.stack2.append(self.stack1.pop())
        return self.stack2.pop()
