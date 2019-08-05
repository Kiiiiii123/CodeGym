//分治
public class Solution {
    public int[] ProductExceptSelf(int[] nums) {
        int[] ans = new int[nums.Length] ;
        
        int k = 1 ;
        for( int i = 0 ; i < nums.Length ; i++ )
        {
            ans[i] = k ;
            k *= nums[i] ; //当前数左边的乘积
        }
        
        k = 1 ;
        for( int i = nums.Length - 1 ; i >= 0 ; i-- )
        {
            ans[i] *= k ;
            k *= nums[i] ; //当前数字右边的乘积
        }
        
        return ans;
    }
}
