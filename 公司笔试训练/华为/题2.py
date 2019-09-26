'''
题目：给定[low,high)范围，先求出该范围内所有的素数，输出所有素数的十位数之和与个位数之和较小的值。
示例：输入：151 160 输出：8
'''

'''
方法： 质数（Prime number，又称素数），指在大于1的自然数中，除了1和该数自身外，无法被其他自然数整除的数（也可定义为只有1与该数本身两个正因数的数）
这里分两步处理问题。
'''

if __name__=='__main__':
  number=input()
  low=int(number.split(' ')[0])
  high=int(number.split(' ')[1])
  
  m=n=0
  list=[]
  for i in range(low,high):
    for j in range(2,i):
      if i%j==0:
        break;
    list.append(i)
  for item in list:
    m+=item%10
    n+=item//10%10
  if m>n:
    print(n)
  else:
    print(m)
