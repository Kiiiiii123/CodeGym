'''
题目：编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。
示例：输入：["h","e","l","l","o"] 输出：["o","l","l","e","h"]
'''

'''
方法一： 字符串则先转列表后切片翻转，最后再转成字符串，两次翻转很耗时
'''

class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        temp_list = list(s)
        temp_list[:] = temp_list[::-1]
        s=''.join(temp_list)

'''
方法二： 直接切片翻转
执行用时：240ms
内存消耗：18MB
'''

class Solution:
    # 输入为列表，这里题目简化过了，直接给了列表
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        s[:]=s[::-1]
        
'''
方法三： 常规方法进行替换，面试时仍得写这个
执行用时：236ms
内存消耗：17.7MB
'''

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        for i in range(len(s)//2):
            temp=s[i]
            s[i]=s[-i-1]
            s[-i-1]=temp
