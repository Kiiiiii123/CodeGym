'''
题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的偶数位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。
'''

'''
方法一：新建两个数组分别存放奇数和偶数，最后拼接
运行时间：27ms
占用内存：5724k
'''

class Solution:
    def reOrderArray(self, array):
        # write code here
        odd=[]
        even=[]
        for i in range(len(array)):
            if array[i]%2==0:
                even.append(array[i])
            else:
                odd.append(array[i])
        return odd+even
    
'''
方法二：函数的扩展功能。把函数中的判断条件拿出来，写成一个函数。用python可以一行搞定： lambda大法。
运行时间：32ms
占用内存：5632k
'''

class Solution:
    def reOrderArray(self, array):
        # write code here
        return sorted(array,key=lambda c:c%2,reverse=True)
