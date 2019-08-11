'''
题目：请实现一个函数，将一个字符串中的每个空格替换成“%20”。例如，当字符串为We Are Happy.则经过替换之后的字符串为We%20Are%20Happy。
'''

'''
方法一：先计算最终需要给出的长度，然后建立两个指针p1,p2，p1指向原始字符串的末尾，p2指向替换后的字符串的末尾。同时移动p1,p2, 将p1指的内容逐个复制到p2, 当p1遇到空格时，在p2处插入 %20， p1向前移动一个位置，p2向前移动3个位置，当p1和p2位置重合时，全部替换完成。时间复杂度O(n)
运行时间：24ms
占用内存：5864k
'''

class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        if not isinstance(s,str) or len(s)<=0 or s==None:
            return ''
        
        spaceNum=0
        for i in s:
            if i==' ':
                spaceNum+=1
        
        newStrLen=len(s)+2*spaceNum
        newStr=newStrLen*[None]
        indexOfOrigin,indexOfNew=len(s)-1,newStrLen-1
        
        while indexOfOrigin>=0 and indexOfNew>=indexOfOrigin:
            if s[indexOfOrigin]==' ':
                newStr[indexOfNew-2:indexOfNew+1]=['%','2','0']
                indexOfNew-=3
                indexOfOrigin-=1
            else:
                newStr[indexOfNew]=s[indexOfOrigin]
                indexOfNew-=1
                indexOfOrigin-=1
                
        return ''.join(newStr)
      
 '''
方法二：使用Python函数接口
运行时间：30ms
占用内存：5736k
'''

class Solution:
    # s 源字符串
    def replaceSpace(self, s):
        # write code here
        return s.replace(' ','%20')

