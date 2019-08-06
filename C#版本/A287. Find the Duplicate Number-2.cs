//集合
//ArrayList即是System.Collection 命名空间的类，实为动态数组，基本上可以替代一个数组，与数组不同的是可以使用索引在指定的位置添加和移除项目，动态
//数组会自动重新调整它的大小，允许在列表中进行动态内存分配、增加、搜索、排序各项
public class Solution {
    public int FindDuplicate(int[] nums) {
        ArrayList set = new ArrayList();
        
        for( int i = 0 ; i < nums.Length ; i++)
        {
            if( set.Contains( nums[i]) )
            {
                return nums[i] ;
            }
            else
            {
                set.Add( nums[i] ) ;
            }
        }
        
        return -1 ;
    }
}
