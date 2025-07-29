/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30202
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
#include "vector"
#include "algorithm"
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> ret(n, vector<int>(n, 0));
        int cycle = n / 2; // 顺时针循环的次数
        int mid = n / 2;   // 中心元素
        int startx = 0;    // x轴起始
        int starty = 0;    // y轴起始
        int count = 1;     // 赋值
        int offset = 1;    // 循环1圈减1
        int i, j;
        while (cycle--)
        {
            i = startx;
            j = starty;
            for (; j < n - offset; j++) // 从左向右
                ret[i][j] = count++;

            for (; i < n - offset; i++) // 从上到下
                ret[i][j] = count++;

            for (j; j > starty; j--) // 从右到左
                ret[i][j] = count++;

            for (i; i > startx; i--) // 从下到上
                ret[i][j] = count++;
            // 第二圈开始,已经从(0,0)开始过,所以另起一行
            startx++;
            starty++;
            offset += 1;
        }
        if (n % 2 == 1) // 如果为奇数,中间需要单独赋值
            ret[mid][mid] = count;
        return ret;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */
