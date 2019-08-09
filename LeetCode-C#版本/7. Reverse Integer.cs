//数学计算解决，涉及溢出
public class Solution {
    public int Reverse(int x) {
        int ans = 0 ;
        
        while( x != 0)
        {
            int pop = x % 10 ;
            if( ans > Int32.MaxValue / 10 || ( ans == Int32.MaxValue / 10 && pop > Int32.MaxValue % 10))
            {
                return 0 ;
            }
            if( ans < Int32.MinValue / 10 || ( ans == Int32.MinValue / 10 && pop < Int32.MinValue % 10))
            {
                return 0 ;
            }
            ans = ans * 10 + pop ;
            x /= 10 ;
        }
        return ans ;
    }
}
