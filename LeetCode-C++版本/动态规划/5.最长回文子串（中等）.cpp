/*
给定一个字符串s，找到s中最长的回文子串。你可以假设s的最大长度为1000。
示例：输入："babad"，输出："bab"或者"aba"。
*/

/*方法一：暴力法
暴力法将选出所有子字符串可能的开始和结束位置，并检验是不是回文。
时间复杂度：Ｏ(n^3)　假设n是输入字符串的长度，(n(n-1))/2是此类子字符串（不包括字符本身是回文的一般解决）的总数。因为验证每个子字符串需要Ｏ(n)，所以时间复杂度是Ｏ(n^3)。
空间复杂度：Ｏ(1) 
*/

class Solution {
public:
    string longestPalindrome(string s) {
        string temp = "";
        string res = "";
        for (int i =0;i<s.length();i++){
            for(int j =i;j<s.length();j++){
                temp += s[j];
                string rev = temp;
                std::reverse(rev.begin(),rev.end());
                if(temp == rev){
                    res = res.length()>temp.length()?res:temp;
                }
            }
            temp = "";
        }
        return res;
    }
};
/*超出时间限制*/

/*方法二：动态规划
为了改进暴力法，我们首先观察如何避免在验证回文时进行不必要的重复计算。考虑"ababa"这个示例。如果我们已经知道"bab"是回文，那么很明显"ababa"一定是回文，因为它的左首字母和右首字母是相同的。直观的动态规划解法就是首先初始化一字母和二字母的回文，然后找到所有三字母的回文，并以此类推...
时间复杂度：Ｏ(n^2)　
空间复杂度：Ｏ(n^2) 
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        if(size == 0|| size == 1)
            return s;
        int start = 0;
        int longest = 1;
        vector<vector<int>>  dp(size,vector<int>(size));
        for(int i = 0;i<size;i++)
        {
            dp[i][i] = 1;
            if(i<size-1 && s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                longest = 2;
                start = i;
            }
        }
        for(int length = 3;length<=size;length++)
        {
            for(int left = 0;left + length - 1<size;left++)
            {
                int right = left + length - 1;
                if(s[left] == s[right] && dp[left+1][right-1] == 1)  //状态转移
                {
                    dp[left][right] = 1;
                    start = left;
                    longest = length;
                }
            }
        }
        return s.substr(start,longest);
    }
};
