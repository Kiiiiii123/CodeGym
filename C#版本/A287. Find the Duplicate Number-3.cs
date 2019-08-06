//寻找环形链表环的入口，快慢指针,fast指针行程是slow指针的两倍
public class Solution {
    public int FindDuplicate(int[] nums) {
        int fast = 0 ;
        int slow = 0 ;
        
        while( true )
        {
            fast = nums[nums[fast]] ;
            slow = nums[slow] ;
            
            if( fast == slow )
            {
                fast = 0 ;
                while( nums[fast] != nums[slow] )
                {
                    fast = nums[fast] ;
                    slow = nums[slow] ;
                }
                return nums[slow] ;
            }
        }
    }
}
