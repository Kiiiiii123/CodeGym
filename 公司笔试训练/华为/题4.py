
'''
题目：两种钉子包装，一种一盒9个，一种一盒4个，现有n（1<=n<=200）个钉子，最少买几盒？ 输出数字表示最少需要的盒数，如果不能刚好够n颗则输出-1
示例：输入：13 输出：2
'''

'''
方法：动态规划问题，思路类似于零钱兑换，动态规划遵循一套固定的流程：递归的暴力解法 -> 带备忘录的递归解法 -> 非递归的动态规划解法
'''

if __name__=='__main__':
  coins=[4,9]
  amount=input()
  
  dp=[amount+1 for _ in range(amount+1)]
  dp[0]=0
  for i in range(1,amount+1):
    for j in range(len(coins)):
      # 只有硬币小于当前金额, 才能进行递推
      if coins[j]<=i:
        # dp[i]要么等于自身(已经被计算过),要么等于coins[j](一次) + (i - coins[j])的次数
        dp[i]=min(dp[i],dp[i-coins[j]]+1)
        
  if dp[amount]>amount:
    print(-1)
  else:
    print(dp[amount])
       
  
  
