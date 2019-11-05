/*
给定一个大小为n的数组，找到其中的众数。众数是指在数组中出现次数大于⌊n/2⌋的元素。你可以假设数组是非空的，并且给定的数组总是存在众数。
示例：输入:[3,2,3],输出:3
*/

/*方法：分治法
分治法，把要求解的问题一分为二，在每个分支上再求解，最后汇总。本题中先求出一个mid=(L+R)>>>1，求mid的左边和右边的众数，最后可以求得整个数组的众数。如果只有一个数，返回这个数，因为一个数的众数就是自己。如果左右分支的众数一样，随意返回一个。如果左右分支的众数不一样，则计算左右分支中他们各自众数的数量，返回数量大的，最后就是整个数组的众数。
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return Helper(nums,0,nums.size()-1);
    }

private:
    int Helper(vector<int>& nums,int leftIdx,int rightIdx)
    {
        if(leftIdx == rightIdx)
            return nums[leftIdx];
        int midIdx = (leftIdx+rightIdx)>>1;
        int left = Helper(nums,leftIdx,midIdx);
        int right = Helper(nums,midIdx+1,rightIdx);
        if(left == right)
            return left;
        
        int leftCnt = 0;
        int rightCnt = 0;
        for(int i = leftIdx;i<midIdx;i++)
        {
            if(nums[i] == left)
                leftCnt++;
        }
        for(int i = midIdx;i<rightIdx;i++)
        {
            if(nums[i] == right)
                rightCnt++;
        }
        
        return leftCnt>rightCnt?left:right;
    }
};



