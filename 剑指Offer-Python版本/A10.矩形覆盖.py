'''
题目：我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
'''

'''
方法：递归问题，实际上就是普通的跳台阶问题，一般这类问题就是从后往前思考。
F（0）= 0
F（1）= 1
F（2）= 2
F（n）= F（n-1）+ F（n-2）（n > 2）
运行时间：29ms
占用内存：5912k
'''

class Solution:
    def rectCover(self, number):
        # write code here
        if number<=2:
            return number
        prev,curr=1,2
        for i in range(3,number+1):
            prev,curr=curr,prev+curr
        return curr
