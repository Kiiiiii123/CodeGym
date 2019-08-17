'''
题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
'''

'''
方法一：递归，斐波那契数列的变形f(n)=f(n-1)+f(n-2)，效率低，超出时间上限
'''

class Solution:
    def jumpFloor(self, number):
        # write code here
        if number in (1,2):
            return number
        return self.jumpFloor(number-1)+self.jumpFloor(number-2)

'''
方法二：用循环代替了递归，比上面的代码效率上有较大的提升
运行时间：28ms
占用内存：5864k
'''

class Solution:
    def jumpFloor(self, number):
        # write code here
        if number<=2:
            return number
        pre,cur=1,2
        for i in range(3,number+1):
            pre,cur=cur,pre+cur
        return cur



