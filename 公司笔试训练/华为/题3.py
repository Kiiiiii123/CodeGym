'''
题目：给定三角形周长p，求满足边长为整数且周长为p的直角三角形个数。例如如果一个直角三角形的周长是120，那么它的三边可以是20，48，52，或者24，45，51，还有30，40，50，有3种不同的解
示例：输入：120 输出：3
'''

'''
方法一：枚举法，利用双重循环，会超时 
'''

if __main__=='__main__':
  count=0
  p=input()
  for(int i=1;i<p;i++):
    for(j=i;j<p;j++):
      k=p-i-j
      if i^2+j^2==k^2:
        count+=1
  print(count)
