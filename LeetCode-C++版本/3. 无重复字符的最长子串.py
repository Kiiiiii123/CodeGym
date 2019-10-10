'''
题目：给定一个字符串，请你找出其中不含有重复字符的最长子串的长度。
'''

'''
方法一： 滑动窗口法
执行用时：96ms
内存消耗：13.9MB
'''

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s:
            return 0
        slide_window=list()
        max_len=0
        cur_len=0
        n=len(s)
        for i in range(n):
            val=s[i]
            if not val in slide_window:
                slide_window.append(val)
                cur_len+=1
            else:
                val_index=slide_window.index(val)
                slide_window=slide_window[val_index+1:]
                slide_window.append(val)
                cur_len=len(slide_window)
            if cur_len>max_len:
                max_len=cur_len
        return max_len

