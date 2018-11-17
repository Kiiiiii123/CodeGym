#3. Longest Substring Without Repeating Characters
#   Given a string, find the length of the longest substring without repeating characters.
#   Example 1:
#       Input: "abcabcbb"
#       Output: 3 
#       Explanation: The answer is "abc", with the length of 3.
#   Example 2:
#       Input: "bbbbb"
#       Output: 1
#       Explanation: The answer is "b", with the length of 1. 
#   Example 3:
#       Input: "pwwkew"
#       Output: 3
#       Explanation: The answer is "wke", with the length of 3. 
#                  Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dict={}
        start=length=0
        for i in range(len(s)):
            if start+length>=len(s):
                return length
            if s[i] in dict and start<=dict[s[i]]:
                start=dict[s[i]]+1
            else:
                length=max(length,i-start+1)
            dict[s[i]]=i
        return length
#解题思路：遍历字符串中的每一个字符放入字典中，遇到字典中还没有的就刷新返回的长度，遇到字典中已经存在的则重置计算长度的初始位置start，注意整个计数过程是可以提前结束的