'''
题目：大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0）。
n<=39
'''

'''
运行时间：34ms
占用内存：5732k
'''

class Solution:
    def Fibonacci(self, n):
        # write code here
        Array=[0,1]
        while(len(Array)<=n):
            Array.append(Array[-1]+Array[-2])
        return Array[n]
