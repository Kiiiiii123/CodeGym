//回文数
//负数一定不是回文数，正数则先计算出倒序数值，再与原数值进行比较
public class Solution {
    public bool IsPalindrome(int x) {
        int num = x ;
        int cur = 0 ;
        
        if ( x < 0 )
        {
            return false ;
        }
        while ( num != 0 )
        {
            cur = cur * 10 + num % 10 ;
            num /= 10 ;
        }
        return cur == x ;
    }
}
