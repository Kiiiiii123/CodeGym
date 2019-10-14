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
