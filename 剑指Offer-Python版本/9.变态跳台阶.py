'''
题目：一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
'''

'''
方法：斐波那契数列的变形，f(n) = f(n-1)+f(n-2)+...+f(n-(n-1)) + f(n-n)
                        f(0) + f(1) + f(2) + f(3) + ... + f(n-1) = f(n) = 2*f(n-1)
运行时间：24ms
占用内存：5752k
'''

class Solution:
    def jumpFloorII(self, number):
        # write code here
        ans=1
        if number>=2:
            for i in range(2,number+1):
                ans=ans*2
        return ans
