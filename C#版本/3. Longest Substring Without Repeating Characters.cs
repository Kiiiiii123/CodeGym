//滑动窗口
public class Solution {
    public int LengthOfLongestSubstring(string s) {
        List<char> characters=new List<char>();
        int subNum=0;
        int strNum=s.Length;
        for(int i=0;i<strNum;i++)
        {
            if(characters.Contains(s[i]))
            {
                characters.RemoveRange(0,characters.IndexOf(s[i])+1);
            }
            characters.Add(s[i]);
            subNum=characters.Count()>subNum?characters.Count():subNum;
        }
        return subNum;
    }
}
