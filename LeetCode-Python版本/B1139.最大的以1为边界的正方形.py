'''
题目：给你一个由若干0和1组成的二维网格grid，请你找出边界全部由1组成的最大正方形子网格，并返回该子网格中的元素数量。如果不存在，则返回 0。
示例：输入：grid = [[1,1,1],[1,0,1],[1,1,1]] 输出：9
提示：
    1 <= grid.length <= 100
    1 <= grid[0].length <= 100
    grid[i][j] 为 0 或 1
'''

'''
方法一：二维数组的数据统计相关，首先想到的是暴力法，时间复杂度O(n^4)
执行用时：1032ms
内存消耗：13.8MB
'''

class Solution:
    def largest1BorderedSquare(self, grid: List[List[int]]) -> int:
        length,width=len(grid),len(grid[0])

        def check_func(x1,y1,x2,y2):
            for x in range(x1,x2):
                if grid[x][y1]!=1 or grid[x][y2-1]!=1:
                    return False
            for y in range(y1,y2):
                if grid[x1][y]!=1 or grid[x2-1][y]!=1:
                    return False
            return True

        for k in range(min(length,width),0,-1):
            # 可供选择的x1
            for x1 in range(length):
                if x1+k>length:
                    break
                for y1 in range(width):
                    x2,y2=x1+k,y1+k
                    # 可供选择的y1
                    if y2>width:
                        break
                    if check_func(x1,y1,x2,y2):
                        return k**2
    
        return 0
