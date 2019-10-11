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
首先对数组进行遍历，当前最大连续子序列和为sum，结果为res，如果sum>０，则说明sum对结果有增益，则sum保留并加上当前遍历的数字，如果sum<=0，则说明sum对结果无增益，需要舍弃，则sum直接更新为当前遍历数字。每次比较sum和res的大小，将最大值置为res，遍历结束返回结果。
时间复杂度：Ｏ(n)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int sum = 0;
        for(int i = 0;i<nums.size();++i)
        {
            if(sum > 0)
            {
                sum += nums[i];
            }else{
                sum = nums[i];
            }
            res = max(res,sum);
        }
        return res;
    }
};
