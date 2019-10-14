/*
给定两个字符串text1和text2，返回这两个字符串的最长公共子序列。
一个字符串的子序列是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。例如，"ace" 是 "abcde" 的子序列，但"aec"不是"abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
若这两个字符串没有公共子序列，则返回0。
提示：1<=text1.length<=1000,1<=text2.length<=1000。
*/

/*方法：动态规划
1.S{s1,s2,s3....si} T{t1,t2,t3,t4....tj}
2.子问题划分
(1)如果S的最后一位等于T的最后一位，则最大子序列就是{s1,s2,s3...si-1}和{t1,t2,t3...tj-1}的最大子序列+1
(2)如果S的最后一位不等于T的最后一位，那么最大子序列就是
①{s1,s2,s3..si}和{t1,t2,t3...tj-1}最大子序列
②{s1,s2,s3...si-1}和{t1,t2,t3....tj}最大子序列
以上两个子序列的最大值
3.边界
只剩下{s1}和{t1}，如果相等就返回1，不等就返回0
4.使用一个表格来存储dp的结果
如果S[i] == T[j] 则dp[i][j] = dp[i-1][j-1] + 1
否则dp[i][j] = max(dp[i][j-1],dp[i-1][j])
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        vector<vector<int>> dp(len1+1,vector<int>(len2+1,0));
        for(int i = 1;i<=len1;++i)
        {
            for(int j = 1;j<=len2;++j)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else
                {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
