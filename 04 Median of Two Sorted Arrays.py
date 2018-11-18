#4. Median of Two Sorted Arrays
#   There are two sorted arrays nums1 and nums2 of size m and n respectively.
#   Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
#   You may assume nums1 and nums2 cannot be both empty.
#   Example 1:
#       nums1 = [1, 3]
#       nums2 = [2]
#       The median is 2.0
#   Example 2:
#       nums1 = [1, 2]
#       nums2 = [3, 4]
#       The median is (2 + 3)/2 = 2.5class Solution:
def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        list=[]
        len1,len2=len(nums1),len(nums2)
        i=j=0
        while i < len1 and j < len2:
            if nums1[i] <= nums2[j]:
                list.append(nums1[i])
                i+=1
            else:
                list.append(nums2[j])
                j+=1
        if i < len1:
            list.extend(nums1[i:])
        elif j < len2:
            list.extend(nums2[j:])
        
        mid=(len1+len2)//2
        if (len1+len2)%2:
            return list[mid]
        else:
            return (list[mid]+list[mid-1])/2.0
#解题思路：先进行排序，后根据总的数字的数量选择返回什么值作为中位数，中位数应该是能够将数组完全分割成长度相等的两个子数组的数字