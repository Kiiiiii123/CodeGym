'''
题目：对于一个正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。给定一个整数n，如果他是完美数，返回True，否则返回False.
示例：输入: 28 输出：True 解释：28 = 1 + 2 + 4 + 7 + 14  提示：输入的数字n不会超过 100,000,000. (1e8)
'''

'''
方法：数学问题，导入数学模块涉及到常见的求因子，套用代码即可，从1 ~ sqrt(num)的范围循环找出num的因子factor，如果factor != 1，那么可以求出另一个与之对应的因子num / factor。这里注意要判断num / factor是否与factor相等，避免相同因子重复添加，计算所有因子和，判断是否与num相等。
执行用时：44ms
内存消耗：13.8MB
'''

import math
class Solution:
    def checkPerfectNumber(self, num: int) -> bool:
        if num<=1:
            return False
        sum=0
        for factor in range(1,int(math.sqrt(num))+1):
            if num%factor==0:
                sum+=factor
                # 因子是互相对应的，这里判别一下是不是两个相同因子
                if factor!=1 and factor!=num/factor:
                    sum+=num/factor
        
        if sum==num:
            return True
        else:
            return False


