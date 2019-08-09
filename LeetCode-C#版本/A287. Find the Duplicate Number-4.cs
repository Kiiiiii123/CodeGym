//二分法
public class Solution {
    public int FindDuplicate(int[] nums) {
        int left = 1 ;
        int right =nums.Length ;
        
        while( left < right )
        {
            int mid = ( left + right )/2 ;
            int count = 0 ;
            for(int i = 0 ; i < nums.Length ; i++ )
            {
                if( nums[i] <= mid )
                    count++ ;
            }
            if( count <= mid )
            {
                left = mid + 1 ;
            }else
            {
                right = mid ;
            }
        }
        return right ;
    }
}
