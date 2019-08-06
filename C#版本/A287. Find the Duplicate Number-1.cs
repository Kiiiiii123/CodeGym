//排序
//先排序后比较，如果前后相同则返回，排序调用的时间复杂度O(nlogn)，空间复杂度O(n)或O(1)，因为不能修改输入数组，排序分配空间恒定
public class Solution {
    public int FindDuplicate(int[] nums) {
        Array.Sort( nums ) ;
        
        for( int i = 1 ; i < nums.Length ; i++)
        {
            if( nums[i] == nums[i-1] )
            {
                return nums[i] ;
            }
        }

        return -1 ;
    }
}
