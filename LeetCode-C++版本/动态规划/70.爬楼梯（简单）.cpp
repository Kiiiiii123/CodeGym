/*
假设你正在爬楼梯。需要n阶你才能到达楼顶。每次你可以爬1或2个台阶。你有多少种不同的方法可以爬到楼顶呢？注意：给定n是一个正整数。
示例：输入：３，输出：３　解释：有三种方法可以爬到楼顶：1阶 + 1阶 + 1阶；1阶 + 2阶；2阶 + 1阶。
*/

/*方法一：暴力法
在暴力法中，我们将会把所有可能爬的阶数进行组合，也就是1和2。而在每一步中我们都会继续调用climbStairs这个函数模拟爬1阶和2阶的情形，并返回两个函数的返回值之和。
climb_Stairs(i,n)=(i+1,n)+climb_Stairs(i+2,n) 其中i定义了当前阶数，而n定义了目标阶数。
时间复杂度：Ｏ(2^n)　树型递归的大小为２^n。
空间复杂度：Ｏ(n) 递归树的深度可以达到n。
*/

class Solution {
public:
    int climbStairs(int n) {
        return climb_Stairs(0,n);
    }
    
    int climb_Stairs(int i,int n){
        if(i > n)
            return 0;
        if(i == n)
            return 1;
        return climb_Stairs(i+1,n)+climb_Stairs(i+2,n);
    }
};
/*注：时间超出限制*/

/*方法二：记忆化递归
在上一种方法中，我们计算每一步的结果时出现了冗余。另一种思路是，我们可以把每一步的结果，存储在demo数组之中，每当函数再次被调用，我们就直接从数组中返回结果。在demo数组的帮助下，我们得到了一个修复的递归树，其大小减少到n。
时间复杂度：Ｏ(n) 
空间复杂度：Ｏ(n) 
*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> demo(n+1,-1);
        return climb_Stairs(0,n,demo);
    }
    
    int climb_Stairs(int i,int n,vector<int> &demo){
        if(i > n)
            return 0;
        if(i == n)
            return 1;
        if(demo[i]>0)
            return demo[i];
        demo[i] = climb_Stairs(i+1,n,demo) + climb_Stairs(i+2,n,demo);
        return demo[i];
    }
};

/*方法三：动态规划
不难发现，这个问题可以被分解为一些包含最优子结构的子问题，即它的最优解可以从其子问题的最优解来有效地构建，所以可以使用动态规划来解决这一问题。第i阶可以由以下两种方法得到：在第(i-1)阶后向上爬一阶，在第(i-２)阶后向上爬二阶，所以达到第i阶的方法的总数就是第(i-1)阶和第(i-2)阶的方法数之和。
时间复杂度：Ｏ(n) 单循环到了n。
空间复杂度：Ｏ(n) dp数组用到了n的空间。
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        vector<int> demo(n+1,-1);
        demo[1] = 1;
        demo[2] = 2;
        for(int i=3;i<=n;i++){
            demo[i] = demo[i-1] + demo[i-2];
        }
        return demo[n];
    }
};

/*方法四：斐波那契数
在上述方法中，我们使用dp数组，其中dp[i] = dp[i-1] +　dp[i-2]，可以很容易通过分析得出dp[i]其实是第i个斐波那契数，现在我们找出以１和２作为第一项和第二项的斐波那契数列中的第n个数。
时间复杂度：Ｏ(n)　单循环到n，需要计算第n个斐波那契数。
时间复杂度：Ｏ(1)　使用常量级空间。
*/
