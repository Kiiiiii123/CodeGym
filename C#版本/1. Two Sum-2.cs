//不使用Add方法而使用索引器
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int> pairs=new Dictionary<int,int>();
        for(int i=0;i<nums.Length;i++)
        {
            if(pairs.ContainsKey(target-nums[i]))
            {
                return new int[]{i,pairs[target-nums[i]]};
            }
            else
            {
                pairs[nums[i]]=i;
            }
        }
        return new int[]{};
    }
}
