#1. Two Sum
#   Given an array of integers, return indices of the two numbers such that they add up to a specific target.
#   You may assume that each input would have exactly one solution, and you may not use the same element twice.
#   Example:
#       Given nums = [2, 7, 11, 15], target = 9,
#       Because nums[0] + nums[1] = 2 + 7 = 9,
#       return [0, 1].
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict={}
        for i in range(len(nums)):
            result=target-nums[i]
            if result in dict:
                return [dict[result],i]
            dict[nums[i]]=i
#解题思路：遍历传入数组中的元素，将它们在字典中对号入座，再次对它们进行查询时，看它们是不是现在遍历的数组中的值的差值，是的话一起返回索引