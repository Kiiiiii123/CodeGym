/*
给定一个整数数组nums，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例：输入：[-2,1,-3,4,-1,2,1,-5,4],输出：６，解释:连续子数组[4,-1,2,1]的和最大，为6。
进阶：如果你已经实现复杂度为O(n)的解法，尝试使用更为精妙的分治法求解。
*/

/*方法一：暴力法
通过双层循环，穷举所有的子区间，然后再对子区间内的所有元素求和。
时间复杂度：Ｏ(n^2)
空间复杂度：Ｏ(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT32_MIN;
        for(int i = 0;i<nums.size();++i)
        {
            int sum = 0;
            for(int j = i;j<nums.size();++j)
            {
                sum += nums[j];
                res = max(res,sum);
            }
        }
        return res;
    }
};

/*方法二：动态规划
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int max = nums[0];
        int dp[size];
        dp[0] = nums[0];
        for(int i = 1;i<size;++i)
        {
            if(dp[i-1] + nums[i] > nums[i])
                dp[i] = dp[i-1] + nums[i];
            else
                dp[i] = nums[i];
            max = max>dp[i]?max:dp[i];
        }
        return max;
    }
};
