/*
给定一个整数数组nums和一个目标值target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
示例：给定nums = [2,7,11,15],target = 9，因为nums[0] + nums[1] = 2 + 7 = 9,所以返回[0,1]
*/

/*方法一：暴力法，遍历每个元素x，并查找是否存在一个值与target-x相等的目标元素。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(i = 0 ;i<nums.size()-1;i++)
        {
            for(j = i+1;j<nums.size();j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    return {i,j};
                }
            }
        }
        return {i,j};
    }
};

/*方法二：

