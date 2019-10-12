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
