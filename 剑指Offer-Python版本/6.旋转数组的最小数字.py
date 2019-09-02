'''
题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。NOTE：给出的所有元素都大于0，若数组大小为0，请返回0。
'''

'''
方法：二分查找：每次查找都把旋转数组平均分成两部分，通过比较当前旋转数组两端点和中间点的值，判断最小值在数组的哪一部分，从而达到缩小搜索范围的目的。其中，两端点为当前的旋转数组索引最小和索引最大的元素，中间点为这两部分子数组的连结元素，也可以看做为轴枢点（pivot point），这里取旋转数组的最小索引和最大索引的算术平均值（向下取整）作为索引，其对应的元素作为中间点。
运行时间：685ms
占用内存：5860k
'''

class Solution:
    def minNumberInRotateArray(self, rotateArray):
        # write code here
        p1=0
        p2=len(rotateArray)-1
        mid=p1
        while rotateArray[p1]>=rotateArray[p2]:
            if p2-p1==1:
                mid=p2
                break
            mid=(p1+p2)>>1 #右移位运算符
            if rotateArray[mid]>=rotateArray[p1]:
                p1=mid
            if rotateArray[mid]<=rotateArray[p2]:
                p2=mid   
        return rotateArray[mid]
