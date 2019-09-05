'''
题目：给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。保证base和exponent不同时为0。
'''

'''
方法一：使用循环。exponent是整数，可能是0、正数或者负数。当其为正数时直接使用循环；当其为负数先求出其绝对值的结果，再取倒数；当其为0时直接返回base。
运行时间：28ms
占用内存：5872k
'''

class Solution:
    def Power(self, base, exponent):
        # write code here
        if exponent<0:
            return 1/self.getPower(base,-exponent)
        elif exponent==0:
            return 1
        else:
            return self.getPower(base,exponent)
        
    def getPower(self,base,exponent):
        if base==0:
            return 0
        result=1
        for i in range(exponent):
            result*=base
        return result

'''
方法二：exponent分为偶数和奇数，通过递归提高运行速度
运行时间：27ms
占用内存：5752k
'''

class Solution:
    def Power(self, base, exponent):
        # write code here
        if exponent<0:
            return 1/self.getPower(base,-exponent)
        elif exponent==0:
            return 1
        elif exponent==1:
            return base
        else:
            return self.getPower(base,exponent)
        
    def getPower(self,base,exponent):
        if base==0:
            return 0
        result=self.Power(base,exponent>>1)
        result*=result
        if exponent&1==1:
            result*=base
        return result
