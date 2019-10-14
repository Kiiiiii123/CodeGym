/*
给定不同面额的硬币coins和一个总金额amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回-1。
示例：输入：coins = [1,2,5],amount = 11，输出：３，解释：11 = 5 + 5 + 1。说明：可以认为每种硬币的数量是无限的。
*/

/*方法一：暴力法
根据最优子结构进行暴力递归。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        int minSum = INT_MAX;
        for(int coin:coins)
        {
            if(amount<coin)
                continue;  //跳出。
            int sub = coinChange(coins,amount-coin);
            if(sub == -1)
                continue;  //跳出。
            minSum = min(minSum,1 + sub);
        }
        return minSum == INT_MAX?-1:minSum;  
    }
};

/*方法二：带备忘录的递归算法
备忘录能大大减少子问题的数量，完全消除子问题的冗余。实际上带备忘录的递归解法的效率已经和动态规划一样了，只不过这种方法叫做自顶向下－递归树从上向下延伸，规模逐渐分解，逐层返回答案。
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(1+amount,-2);
        return helper(coins,amount,memo);
    }
    
    int helper(vector<int>& coins,int amount,vector<int>& memo)
    {
        if(amount == 0)
            return 0;
        if(memo[amount] != -2)
            return memo[amount];
        int minSum = INT_MAX;
        for(int coin:coins)
        {
            if(amount<coin)
                continue;
            int sub = helper(coins,amount-coin,memo);
            if(sub == -1)
                continue;
            minSum = min(minSum,1 + sub);
        }
        memo[amount] = minSum == INT_MAX?-1:minSum;
        return  memo[amount];
    }
};

/*方法三：动态规划
自底向上的动态规划，从最小规模的问题向上推，动态规划一般都脱离了递归，由循环迭代完成计算。
*/
