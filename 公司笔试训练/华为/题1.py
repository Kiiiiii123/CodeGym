'''
题目：输入输出格式为：第一个字符为输入或输出字符的长度（包含该位置），随后的字符中若出现‘A’，则在输出中将它替换成‘12 34’,；若出现‘B’，将它替换成‘AB CD’；其他字符保持不变。
示例：输入：8 1 2 3 4 5 6 A 输出：9 1 2 3 4 5 6 12 34
'''

'''
方法： 使用res模块进行字符串字符替换
'''

import re 
if __name__=='__main__':
  result=input()
  first=0
  if 'A' in s:
    s=re.sub('A','12 34',s)
    s=re.sub('B','AB CD',s)
first=len(s.split(' '))
print(first,s[1:])
