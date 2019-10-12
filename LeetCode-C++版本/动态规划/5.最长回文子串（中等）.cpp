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

/*方法二：

*/
